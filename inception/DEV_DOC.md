# DEV_DOC - Developer and Infrastructure Documentation

This document describes the technical implementation details, architectural prerequisites, local configuration parameters, and container life-cycle management protocols for developers maintaining or auditing this infrastructure.

---

## 1. Environment Setup from Scratch

To deploy a matching mirror of this staging network, the local host machine must fulfill specific structural and filesystem dependencies.

### Installation Prerequisites
Ensure the target Virtual Machine or local engine contains the required compilation tools:
* **Docker Engine** (v20.10 or higher)
* **Docker Compose plugin** (v2.0 or higher)
* **GNU Make** (Standard development utils suite)

### Secrets and Directory Isolation
1. **Host Storage Directories:** The Docker engine relies on named volume directories mapped directly inside the current active user home path. The automation script initializes these locations, remenber changing "analba-s" with your own login:
   * `/home/analba-s/data/wordpress`
   * `/home/analba-s/data/mariadb`

2. **Security Credentials Setup:** Confidential data is explicitly kept out of the repository codebase. Before launching, a secure uncommitted folder called `secrets/` must reside at the root of the project with the following configuration files containing text tokens (no trailing newlines or spaces):
   * `secrets/db_root_password.txt` — Root password token for MariaDB initialization.
   * `secrets/db_password.txt` — WordPress storage access account passphrase.
   * `secrets/wp_admin_password.txt` — Administrative panel password asset.
   * `secrets/wp_user_password.txt` — Secondary standard author credential token.

   > ⚠️ **Warning:** The secrets/files.txt has to include only the password and nothing else.
	```bash
	cat secrets/db_pwassword.txt
	```
	*Expected Output:*
		this_is_my_pasword ✅

		password="this_is_my_password" ❌

3. **Environmental Global Variables:** Configuration mappings are controlled via the `srcs/.env` file. A standard `.env` prototype configuration must provide:
   ```env
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

---

## 2. Building and Launching with the Makefile

The infrastructure orchestration relies entirely on `Makefile` macros automating network bindings, directory permissions, system mapping, and image execution.

### Compilation Protocols

* **Deploy Core Application Cluster:**
Compiles individual Dockerfiles without downloading generic stacks, ensures host paths are alive, configures the `/etc/hosts` resolution entry, and runs detached services:
```bash
make

```


* **Graceful Network Tear Down:**
Stops container operations while maintaining active database storage states intact:
```bash
make down

```


* **Soft System Cleanup:**
Removes existing containers and network bridges, purging associated volatile runtime states:
```bash
make clean

```


* **Hard Environment Purge (Prune & Reset):**
Triggers a full teardown. Destroys images, drops volumes, prunes the Docker build cache, resets local loopbacks, and completely purges the directory storage tree on the host (`/home/analba-s/data`):
```bash
make fclean

```


* **Full Re-compilation Cycle:**
Triggers an automated clean sequence followed immediately by a zero-cache infrastructure initialization:
```bash
make re

```



---

## 3. Container and Volume Management Reference

Developers managing the active services can interact with the engine daemon through standard administrative CLI execution pathways:

### Container Status Auditing

Verify structural container states, resource ports, names, and processing lifecycles:

```bash
docker ps -a

```

### Inspecting Software Networks

Audit the private isolated microservice software bridge network namespace (`srcs_inception_network`):

```bash
docker network ls
docker network inspect srcs_inception_network

```

### Investigating Storage Volatiles

Verify that Docker engine abstracts the volume persistence bindings correctly:

```bash
docker volume ls
docker volume inspect wordpress_files
docker volume inspect database_store

```

### Checking database

	Logging in:

	```bash
		docker exec -it mariadb mysql -u db_username -p

	```

	Checking database:

	```bash
		use inception_db;
		show tables;

	```

---

## 4. Storage Architecture and Data Persistence

Data persistency complies strictly with the requirements of the project, discarding temporary mount methodologies (bind mounts) for crucial application layers:

### Storage Architecture Design

* **`database_store` Volume:** Maps natively inside the MariaDB container to `/var/lib/mysql`. It ensures relational tables, schemas, and metadata are never volatile.
* **`wordpress_files` Volume:** Maps natively inside the WordPress processing container to `/var/www/html`. It hosts the downloaded WordPress core files, asset configurations, styles, and custom media uploads.

### Host Physical Mappings

The Docker engine redirects data streams out of the isolated processing nodes down onto the underlying persistent infrastructure layer of the host system. When the application stack is operating, data persists physically under:

* **MariaDB Files Engine Storage:** `/home/analba-s/data/mariadb`
* **WordPress Assets Core Storage:** `/home/analba-s/data/wordpress`

Because these assets are bound directly to named volumes managed by the Docker engine daemon, code rebuilds, runtime container failures, or cluster updates will not erase, corrupt, or alter any application database states or frontend file changes.

