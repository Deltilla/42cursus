# USER_DOC - End User and Administrator Documentation

This documentation provides clear, simple, and essential guidelines for administrators or end-users to operate, access, and verify the microservice stack deployed via this infrastructure.

---

## 1. Services Provided by the Stack
The infrastructure initializes and connects three dedicated microservices running under strict network isolation:
* **NGINX:** The unified, secure entry point of the infrastructure. It intercepts external traffic over HTTPS, handles TLS decryption, and serves assets or reverse-proxies scripts.
* **WordPress (PHP-FPM):** The core content management processing engine. It executes backend PHP scripts and builds the functional website.
* **MariaDB:** The isolated relational database engine. It stores user tables, site taxonomies, post objects, and system configurations securely.

---

## 2. Starting and Stopping the Project

### To Start the Stack
Run the execution command from the root folder. This automatically sets up network namespaces, local persistent host directories, routes the domain names, builds custom images, and launches containers:
```bash
make

```

### To Stop the Stack

To halt all running processes without destroying any user databases or persistent website uploads:

```bash
make down

```

### Complete Environment Purge

To tear down the containers, delete the custom base images, drop networks, and completely erase data volumes from `/home/analba-s/data/`:

```bash
make fclean

```

---

## 3. Accessing the Website and Administration Panel

Before accessing the endpoints, ensure your domain routing is active. The application maps to your unique host allocation loopback domain.

* **Main WordPress Website (Public Frontend):**
Open your web browser and navigate to:
`https://analba-s.42.fr`
* **WordPress Administration Dashboard (Backend Panel):**
To manage plugins, write posts, or audit users, access the admin portal at:
`https://analba-s.42.fr/wp-admin`

> ⚠️ **Security Warning:** Since the TLS certificate implemented is self-signed for development, your browser will display an "Advanced Security Warning". Click **"Advanced"** and select **"Accept the Risk and Continue" / "Proceed to analba-s.42.fr"** to view the site.

---

## 4. Locating and Managing Credentials

To maintain strict compliance with security protocols, no plain-text passwords exist within the code repository.

* **Configuration Settings:** Non-sensitive variables (such as Database Names, DB Users, or Admin Names) are located inside:
`srcs/.env`
```
# Configuración de Dominio
DOMAIN_NAME=login.42.fr


# Configuración de Base de Datos (Para MariaDB y WordPress)
MYSQL_DATABASE=inception_db
MYSQL_USER=db_username

# Configuración de WordPress
WP_ADMIN_USER=admin_username
WP_USER=wp_username
WP_URL=https://${DOMAIN_NAME}
WP_TITLE=login Inception
WP_ADMIN_EMAIL=${WP_ADMIN_USER}@${DOMAIN_NAME}
WP_USER_EMAIL=${WP_USER}@${DOMAIN_NAME}

```

* **Secure Production Secrets:** Crucial operational keys, Root DB credentials, and application administrative passwords reside locally on the host machine inside the uncommitted directory:
`secrets/`
* `secrets/db_root_password.txt` — MariaDB root account token.
* `secrets/db_password.txt` — WordPress native database connection key.
* `secrets/wp_admin_password.txt` — Admin user access passphrase.
* `secrets/wp_user_password.txt` — Standard user role access passphrase.

> ⚠️ **Warning:** The secrets/files.txt has to include only the password and nothing else.
```bash
cat secrets/db_pwassword.txt
```
*Expected Output:*
	this_is_my_pasword ✅

	password="this_is_my_password" ❌


---

## 5. Checking Service Health and Status

To verify that the microservices are running normally, use the following monitoring tools:

### Container Status Verification

Run this command to print active containers, mapped exposed ports, and current runtimes:

```bash
docker ps

```

*Expected Output:* You must see `nginx`, `wordpress`, and `mariadb` running with an `Up` status status indicator.

### Checking Real-time Service Logs

If you experience service drops or want to monitor operational events, view container outputs via:

```bash
# General cluster logs
docker compose -f srcs/docker-compose.yml logs

# Targeted container tracking
docker logs nginx
docker logs wordpress
docker logs mariadb

```
