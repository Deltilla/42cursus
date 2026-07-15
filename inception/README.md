*This project has been created as part of the 42 curriculum by analba-s.*

# Inception - System Administration with Docker Compose

## Description
Inception is a foundational System Administration project designed to build a complete, multi-container infrastructure utilizing Docker Compose on a personal Virtual Machine. The core goal of this project is to deepen the understanding of virtualization, containerization, and networking microservices.

Instead of deploying pre-made monolithic stacks or downloading black-box images from DockerHub, every component in this infrastructure is built independently using custom Dockerfiles based on a minimal stable environment. The system establishes a secure web hosting architecture featuring an NGINX TLS entrypoint, a WordPress processing engine powered by PHP-FPM, and an isolated MariaDB database instance.

---

## Technical Design & Infrastructure Choices

To guarantee complete comprehension of virtualization concepts, the project requires architectural comparisons across key components:

### 1. Virtual Machines vs Docker Containers
* **Virtual Machines (VMs):** Virtualize hardware layers by using a Hypervisor (such as VirtualBox) to run a fully independent Guest Operating System. Each VM contains its own kernel, virtual memory, and virtual drivers, leading to high resource overhead, slow boot times (minutes), and large image snapshots (gigabytes).
* **Docker Containers:** Virtualize at the OS-level (the kernel layer). Containers share the Host OS kernel via namespaces and cgroups, isolating only the binaries, libraries, and application runtimes. This results in ultra-lightweight deployments, instantaneous initialization (seconds), minimal CPU/RAM overhead, and strict process isolation.

### 2. Secrets vs Environment Variables
* **Environment Variables:** Ideal for non-sensitive configuration states (e.g., domain names, titles, database usernames). They are injected into the container shell environment but remain visible via commands like `docker inspect`, making them highly vulnerable if used for passwords.
* **Docker Secrets:** Designed strictly for confidential credentials (e.g., DB root passwords, admin tokens). Secrets are mounted natively as secure, temporary in-memory files within `/run/secrets/` inside the target container. They never hit the disk unencrypted and are not exposed via inspecting commands, preventing security breaches in git repositories.

### 3. Docker Network vs Host Network
* **Host Network:** The container shares the host machine's networking namespace directly, bypassing Docker's virtual routing layers. While performance is raw, it strips away application isolation, opening security vectors and creating port allocation conflicts on the host.
* **Docker Network (Bridge):** Creates an isolated, virtual software-defined bridge interface. Containers are assigned private internal IPs and communicate inside an exclusive sub-network via custom DNS resolution (using service names). No external ports are accessible except those explicitly forwarded via the NGINX gateway.

### 4. Docker Volumes vs Bind Mounts
* **Bind Mounts:** Maps a direct path from the host machine to a path inside the container. It depends heavily on the specific file structure and file permissions of the host OS, making it less portable and less secure for production instances.
* **Docker Named Volumes:** Managed entirely by the Docker engine daemon ecosystem. Docker abstractly controls the persistent storage lifecycle, managing permissions and data consistency natively. In this configuration, data persists cleanly on the host path `/home/analba-s/data/` across container lifecycles without coupling container configurations to local host dependencies.

---

## Architecture Blueprint

The infrastructure acts as an isolated system where external communication is constrained strictly through NGINX via port 443:


```

[ Client Request ]
│
▼ (Port 443 - HTTPS / TLS v1.3 Only)
┌──────────────┐
│    NGINX     │ ◄──── Encrypted Gateway
└──────┬───────┘
│
▼ (Internal Docker Network - Port 9000)
┌──────────────┐       ┌──────────────┐
│  WordPress   │ ▰▰▰▰► │   MariaDB    │ ◄── Private Data Store (Port 3306)
│  (PHP-FPM)   │       └──────────────┘
└──────┬───────┘
│
▼ (Named Docker Volumes)
[ wordpress_files ] ───► Mounted on Host at /home/analba-s/data/wordpress
[ database_store ]  ───► Mounted on Host at /home/analba-s/data/mariadb

```

---

## Instructions

### Prerequisites
* A clean Virtual Machine running Linux.
* Docker Engine (v20.10+) and Docker Compose plugin installed.
* `sudo` privileges (required by the Makefile to inject the domain name into `/etc/hosts`).

### Installation & Deployment
To install, configure the network automatically, initialize volumes, map hosts, and launch the services:
```bash
make

```

### Stopping the Services

To stop the application gracefully without wiping persistent application data:

```bash
make down

```

### Complete Environment Purge

To tear down the containers, delete the custom base images, drop networks, and completely erase data volumes from `/home/analba-s/data/`:

```bash
make fclean

```

---

## Resources & AI Usage

### References & Documentation

* [Docker Architecture and Best Practices](https://docs.docker.com/)
* [WordPress CLI Configuration Manual](https://make.wordpress.org/cli/)
* [MariaDB Server System Administration Guidelines](https://mariadb.com/kb/en/documentation/)
* [PHP-FPM Configuration & Performance Tuning Guide](https://www.php.net/manual/en/install.fpm.php)

### Artificial Intelligence Implementation Statement

In alignment with the pedagogical principles of the 42 curriculum, Artificial Intelligence (Large Language Models) was used responsibly during this project to act as a research companion and code auditor.

* 
**Information Retrieval & Contextual Mapping:** Used to gather study guides, understand system-level documentation (such as the inner workings of Docker internal bridge networks), and locate high-quality references.


* 
**Debugging and Code Auditing:** AI assisted in analyzing shell pipeline behaviors, tracking network layer propagation delays, and fixing syntactic anomalies—such as debugging a Zend INI parser error triggered by legacy `#` comment characters within the custom PHP-FPM `www.conf` pool configuration.


* 
**Verification and Testing:** Every concept, logic path, and configuration block generated or refined with AI assistance was systematically scrutinized, cross-checked with official documentation, and manually tested within the target VM environment to ensure zero dependency on unverified black-box configurations.



---

## Configuration Reference (Example Template)

| Service 		| Internal Port | Protocol 			| Mounted Volume (Container Path) |
| ------------- | ------------- | ----------------- | ------------------------------- |
| **nginx**     | `443`  		| HTTPS / TLSv1.3   | None (Configuration only)		  |
| **wordpress** | `9000` 		| FastCGI (PHP-FPM) | `/var/www/html`           	  |
| **mariadb**   | `3306` 		| MySQL Native      | `/var/lib/mysql`          	  |
