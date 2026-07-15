#!/bin/bash
set -e

mkdir -p /var/www/html
cd /var/www/html

DB_PASSWORD=$(cat /run/secrets/db_password)
WP_ADMIN_PASSWORD=$(cat /run/secrets/wp_admin_password)
WP_USER_PASSWORD=$(cat /run/secrets/wp_user_password)

if [ ! -f "wp-login.php" ]; then
    echo "WordPress: Descargando la última versión del core..."
    wp core download --allow-root
fi

echo "WordPress: Esperando a que el contenedor MariaDB esté totalmente disponible en el puerto 3306..."
until bash -c "echo > /dev/tcp/mariadb/3306" 2>/dev/null; do
    echo "WordPress: MariaDB aún no responde, reintentando en 2 segundos..."
    sleep 2
done
echo "WordPress: ¡Conexión con MariaDB establecida con éxito en la red!"

if [ ! -f "wp-config.php" ]; then
    echo "WordPress: Creando el archivo wp-config.php..."
    wp config create --allow-root \
        --dbname="${MYSQL_DATABASE}" \
        --dbuser="${MYSQL_USER}" \
        --dbpass="${DB_PASSWORD}" \
        --dbhost="mariadb:3306" \
        --path="/var/www/html"

    echo "WordPress: Instalando el sitio web..."
    wp core install --allow-root \
        --url="${WP_URL}" \
        --title="${WP_TITLE}" \
        --admin_user="${WP_ADMIN_USER}" \
        --admin_password="${WP_ADMIN_PASSWORD}" \
        --admin_email="${WP_ADMIN_EMAIL}" \
        --skip-email

    echo "WordPress: Creando un segundo usuario común..."
    wp user create "${WP_USER}" "${WP_USER_EMAIL}" \
        --role=author \
        --user_pass="${WP_USER_PASSWORD}" \
        --allow-root
        
    echo "WordPress: Configuración e instalación completadas."
else
    echo "WordPress: Ya se encuentra instalado, saltando configuración inicial."
fi

chown -R www-data:www-data /var/www/html

echo "WordPress: Arrancando PHP-FPM en primer plano..."
exec php-fpm8.2 -F