#!/bin/bash
set -e

MYSQL_PASSWORD=$(cat /run/secrets/db_password)
MYSQL_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)

if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "MariaDB: Inicializando el directorio de datos del sistema..."
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
fi

echo "MariaDB: Aplicando/Verificando permisos de red e inyección de datos..."
mysqld_safe --skip-networking &

until mysqladmin ping >/dev/null 2>&1; do
    echo "MariaDB: Esperando al servicio temporal..."
    sleep 1
done

mysql -u root -p"${MYSQL_ROOT_PASSWORD}" << EOF
-- 1. Cambiar la contraseña del root real que existe en la instalación limpia ('localhost')
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';

-- 2. Crear la base de datos dedicada para WordPress si no existe
CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;

-- 3. Crear o actualizar el usuario común que usará WordPress para el host '%'
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
ALTER USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';

-- 4. Darle todos los privilegios a ese usuario sobre la base de datos de WordPress
GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';

-- 5. Aplicar cambios
FLUSH PRIVILEGES;
EOF

echo "MariaDB: Privilegios forzados con éxito."
mysqladmin -u root -p"${MYSQL_ROOT_PASSWORD}" shutdown

echo "MariaDB: Lanzando el servidor definitivo en primer plano..."
exec mysqld --user=mysql --console