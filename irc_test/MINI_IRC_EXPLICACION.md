# Explicación Detallada: mini_irc_test.cpp

## Índice
1. Includes y Headers
2. Función `set_nonblocking()`
3. Función `main()` - Inicialización
4. Bucle Principal con `poll()`
5. Manejo de Conexiones de Clientes
6. Procesamiento de Datos Fragmentados
7. Cierre de Conexiones

---

## 1. INCLUDES Y HEADERS (Líneas 1-15)

```cpp
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>

#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>
```

### ¿Por qué cada header?

| Header | Propósito |
|--------|-----------|
| `<sys/types.h>` | Define tipos estándar (ej: `socklen_t`, `ssize_t`) |
| `<sys/socket.h>` | Funciones de socket (`socket()`, `bind()`, `listen()`, `accept()`, `recv()`, `send()`) |
| `<netinet/in.h>` | Estructuras de red IPv4 (`struct sockaddr_in`) y constantes (`AF_INET`, `SOCK_STREAM`) |
| `<arpa/inet.h>` | Funciones de conversión de red (`htons()`, `htonl()`, `inet_addr()`) |
| `<unistd.h>` | Funciones POSIX (`close()`, `read()`, `write()`) |
| `<fcntl.h>` | Control de files (`fcntl()`) para hacer sockets no bloqueantes |
| `<poll.h>` | Función `poll()` para multiplexación de E/S |
| `<cerrno>` | Manejo de errores (`errno`, `strerror()`) |
| `<cstring>` | Funciones de strings (`memset()`) |
| `<cstdlib>` | Funciones estándar (`atoi()`) |
| `<iostream>` | Entrada/salida estándar (`std::cout`, `std::cerr`) |
| `<string>` | Clase `std::string` para manejar buffers |
| `<vector>` | Clase `std::vector` para array dinámico de `pollfd` |
| `<map>` | Clase `std::map` para diccionario fd -> buffer de cliente |

### ¿Por qué C++98?

- Sin `auto` (especificar tipos explícitamente)
- Sin `nullptr` (usar `0` o `NULL`)
- Sin `std::unordered_map` (usar `std::map`)
- Sin hilos
- Soporta compiladores antiguos

---

## 2. FUNCIÓN `set_nonblocking()` (Líneas 22-26)

```cpp
int set_nonblocking(int fd) {
    int flags = fcntl(fd, F_GETFL, 0);
    if (flags < 0) return -1;
    return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
}
```

### ¿Qué hace?

Convierte un file descriptor (socket) en **no bloqueante**.

### Explicación línea por línea:

```cpp
int flags = fcntl(fd, F_GETFL, 0);
```
- **`fcntl(fd, F_GETFL, 0)`**: Lee los flags actuales del file descriptor `fd`.
  - `F_GETFL` = "Get FLags"
  - Retorna un bitmask con los flags actuales
  - Devuelve `-1` si falla

```cpp
if (flags < 0) return -1;
```
- Si `fcntl()` falló, retorna `-1` para indicar error.

```cpp
return fcntl(fd, F_SETFL, flags | O_NONBLOCK);
```
- **`flags | O_NONBLOCK`**: Combina los flags actuales con la bandera `O_NONBLOCK`.
  - `|` = OR bitwise (añade la bandera sin perder otras)
- **`fcntl(fd, F_SETFL, ...)`**: Escribe los flags modificados.
  - `F_SETFL` = "Set FLags"
  - Si tiene éxito retorna 0, si falla retorna `-1`

### ¿Por qué es importante?

Sin `O_NONBLOCK`, `recv()` se **bloquearía** esperando datos, impidiendo que el servidor atienda otros clientes. Con esta flag, `recv()` retorna inmediatamente aunque no haya datos.

---

## 3. FUNCIÓN `main()` - INICIALIZACIÓN (Líneas 28-71)

### 3.1 Parsing del puerto (Líneas 29-30)

```cpp
int port = 6667;
if (argc >= 2) port = atoi(argv[1]);
```

- `port = 6667`: Puerto por defecto (estándar IRC)
- `argc >= 2`: Si se pasó un argumento desde la línea de comandos
- `atoi(argv[1])`: Convierte el string de puerto a entero

**Ejemplo de uso:**
```bash
./mini_irc_test          # Usa puerto 6667
./mini_irc_test 9000     # Usa puerto 9000
```

### 3.2 Crear el socket del servidor (Líneas 32-36)

```cpp
int server_fd = socket(AF_INET, SOCK_STREAM, 0);
if (server_fd < 0) {
    std::cerr << "socket() failed: " << strerror(errno) << std::endl;
    return 1;
}
```

**Parámetros de `socket()`:**
| Parámetro | Valor | Significado |
|-----------|-------|-------------|
| `domain` | `AF_INET` | IPv4 (si fuese IPv6 sería `AF_INET6`) |
| `type` | `SOCK_STREAM` | TCP (secuencia ordenada de bytes con garantía de entrega) |
| `protocol` | `0` | Protocolo por defecto (automático) |

**¿Qué retorna?**
- Si éxito: Retorna un número >= 0 (file descriptor del socket)
- Si falla: Retorna -1

**¿Por qué verificar `< 0`?**
- Los file descriptors son números >= 0
- Si es negativo, el `socket()` falló

**¿Qué es `strerror(errno)`?**
- `errno`: Variable global que contiene el código de error
- `strerror()`: Convierte el código en mensaje legible (ej: "Permission denied")

### 3.3 SO_REUSEADDR - Evitar "Address already in use" (Líneas 38-42)

```cpp
int one = 1;
if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one)) < 0) {
    std::cerr << "setsockopt() failed: " << strerror(errno) << std::endl;
    close(server_fd);
    return 1;
}
```

**¿Qué hace?**

Permite reutilizar el puerto inmediatamente después de cerrar el servidor.

**Problema sin esta opción:**
```
./mini_irc_test 6667
[Ctrl+C]
./mini_irc_test 6667
# Error: "Address already in use"
# Hay que esperar ~1 minuto (TIME_WAIT)
```

**Con SO_REUSEADDR:**
```
./mini_irc_test 6667
[Ctrl+C]
./mini_irc_test 6667
# ¡Funciona inmediatamente!
```

**Explicación de parámetros:**
```cpp
int one = 1;
setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &one, sizeof(one))
```
- `SOL_SOCKET`: Nivel de socket (opciones del socket mismo)
- `SO_REUSEADDR`: Opción específica (reutilizar dirección)
- `&one`: Puntero al valor (1 = activado)
- `sizeof(one)`: Tamaño del valor

### 3.4 Hacer el socket no bloqueante (Líneas 44-48)

```cpp
if (set_nonblocking(server_fd) < 0) {
    std::cerr << "fcntl() failed: " << strerror(errno) << std::endl;
    close(server_fd);
    return 1;
}
```

Usa la función `set_nonblocking()` que explicamos antes.

**¿Por qué?**
- El `poll()` puede informar que hay conexiones pendientes sin bloquearse
- `accept()` en modo no bloqueante retorna `-1` con `EAGAIN` cuando no hay conexiones

### 3.5 Preparar la estructura de dirección (Líneas 50-55)

```cpp
struct sockaddr_in addr;
memset(&addr, 0, sizeof(addr));
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = htonl(INADDR_ANY);
addr.sin_port = htons(port);
```

**¿Qué es `sockaddr_in`?**

Estructura IPv4 que define:
```
┌─────────────────────────────────┐
│   sin_family (AF_INET)          │ ← Familia de dirección
├─────────────────────────────────┤
│   sin_port (6667)               │ ← Puerto
├─────────────────────────────────┤
│   sin_addr.s_addr (INADDR_ANY)  │ ← Dirección IP
├─────────────────────────────────┤
│   sin_zero (relleno)            │ ← Bytes de padding
└─────────────────────────────────┘
```

**Línea por línea:**

```cpp
memset(&addr, 0, sizeof(addr));
```
- Inicializa toda la estructura a 0 bytes (limpia)
- `memset(destino, valor, tamaño)`

```cpp
addr.sin_family = AF_INET;
```
- Especifica que usamos IPv4

```cpp
addr.sin_addr.s_addr = htonl(INADDR_ANY);
```
- `INADDR_ANY` = "Escuchar en cualquier interfaz" (0.0.0.0)
- `htonl()` = "Host TO Network Long" (convierte byte order)
  - En máquinas x86 (little-endian): Invierte bytes
  - En máquinas big-endian: No hace nada
  - **Siempre usa `htonl()` para valores de red**

```cpp
addr.sin_port = htons(port);
```
- `htons()` = "Host TO Network Short" (convierte 2 bytes)
- Convierte el puerto a formato de red

**¿Por qué `hton`?**

Los procesadores representan números de diferente forma:
```
Little-endian (x86):  0x1234 se almacena como [0x34, 0x12]
Big-endian (PowerPC): 0x1234 se almacena como [0x12, 0x34]

La red siempre usa big-endian (network byte order).
hton* convierte del formato local al de red.
```

### 3.6 Bind - Asociar el socket a dirección y puerto (Líneas 57-61)

```cpp
if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    std::cerr << "bind() failed: " << strerror(errno) << std::endl;
    close(server_fd);
    return 1;
}
```

**¿Qué hace `bind()`?**

Asocia el socket a una dirección IP y puerto específicos.

**Parámetros:**
- `server_fd`: El socket
- `(struct sockaddr *)&addr`: Puntero a la dirección (con cast)
- `sizeof(addr)`: Tamaño de la estructura

**¿Por qué el cast a `(struct sockaddr *)`?**

`bind()` espera un puntero genérico. Las diferencias entre IPv4 y IPv6 están en la estructura interna, pero `sockaddr` es el tipo base.

### 3.7 Listen - Marcar como socket de escucha (Líneas 63-67)

```cpp
if (listen(server_fd, 10) < 0) {
    std::cerr << "listen() failed: " << strerror(errno) << std::endl;
    close(server_fd);
    return 1;
}
```

**¿Qué hace `listen()`?**

Marca el socket como "socket de escucha" y prepara una cola de conexiones.

**Parámetros:**
- `server_fd`: El socket
- `10`: Backlog (máximo de conexiones pendientes en la cola)
  - Si 11 clientes intentan conectar simultáneamente:
    - 10 entran en la cola
    - 1 es rechazado

### 3.8 Mensajes de éxito y preparación (Líneas 69-75)

```cpp
std::cout << "mini_irc_test listening on 0.0.0.0:" << port << std::endl;

std::vector<struct pollfd> fds;
std::map<int, std::string> buffers;

struct pollfd pfd;
pfd.fd = server_fd;
pfd.events = POLLIN;
pfd.revents = 0;
fds.push_back(pfd);
```

**Explicación:**

```cpp
std::cout << "mini_irc_test listening on 0.0.0.0:" << port << std::endl;
```
- Imprime un mensaje de éxito

```cpp
std::vector<struct pollfd> fds;
```
- Array dinámico de estructuras `pollfd`
- Cada elemento = un file descriptor a vigilar

```cpp
std::map<int, std::string> buffers;
```
- Diccionario que mapea `fd → buffer de datos`
- Cada cliente tiene su propio buffer para datos fragmentados

```cpp
struct pollfd pfd;
pfd.fd = server_fd;
pfd.events = POLLIN;
pfd.revents = 0;
```
- Prepara una estructura `pollfd` para el socket del servidor:

| Campo | Valor | Significado |
|-------|-------|-------------|
| `fd` | `server_fd` | Vigilar el socket del servidor |
| `events` | `POLLIN` | Queremos saber cuando hay conexiones (datos de entrada) |
| `revents` | `0` | Se rellena por `poll()` con lo que sucedió |

```cpp
fds.push_back(pfd);
```
- Añade el socket del servidor al array de vigilancia

---

## 4. BUCLE PRINCIPAL CON `poll()` (Líneas 77-167)

```cpp
while (true) {
    int ret = poll(&fds[0], fds.size(), -1);
    // ...
}
```

### 4.1 Llamada a `poll()` (Línea 78)

```cpp
int ret = poll(&fds[0], fds.size(), -1);
```

**¿Qué hace `poll()`?**

Espera hasta que algo suceda en alguno de los file descriptors vigilados.

**Parámetros:**
```
poll(
  &fds[0],        // Array de pollfd (puntero al primer elemento)
  fds.size(),     // Número de elementos en el array
  -1              // Timeout: -1 = espera indefinidamente
)
```

**¿Qué retorna?**
- `> 0`: Número de file descriptors con eventos
- `0`: Timeout alcanzado (con timeout > -1)
- `-1`: Error

**¿Qué se llena en los `revents`?**

Para cada `pollfd`, se rellena `revents` con flags indicando qué sucedió:

| Flag | Significado |
|------|-------------|
| `POLLIN` | Hay datos para leer |
| `POLLOUT` | Socket listo para escribir |
| `POLLHUP` | Desconexión (hangup) |
| `POLLERR` | Error en el socket |

### 4.2 Manejo de errores en `poll()` (Líneas 79-82)

```cpp
if (ret < 0) {
    if (errno == EINTR) continue;
    std::cerr << "poll() failed: " << strerror(errno) << std::endl;
    break;
}
```

**¿Qué errores puede dar `poll()`?**

```cpp
if (errno == EINTR) continue;
```
- `EINTR` = "Interrupted System Call"
- Sucede cuando una señal interrumpe `poll()` (ej: Ctrl+C)
- Solución: Reintentar `poll()` con `continue`

```cpp
std::cerr << "poll() failed: " << strerror(errno) << std::endl;
break;
```
- Otros errores: Imprimir error y salir del bucle

### 4.3 Iterar sobre eventos (Línea 84)

```cpp
for (size_t i = 0; i < fds.size(); ++i) {
```

Itera sobre todos los file descriptors vigilados para ver cuál tiene eventos.

---

## 5. MANEJO DE CONEXIONES DE CLIENTES (Líneas 85-110)

### 5.1 Verificar si hay eventos (Línea 85)

```cpp
if (fds[i].revents & POLLIN) {
```

**¿Qué significa?**

El operador `&` (AND bitwise) verifica si el flag `POLLIN` está presente en `revents`.

**Ejemplo:**
```
revents = POLLIN | POLLOUT = 0b0011
POLLIN                      = 0b0001
revents & POLLIN            = 0b0001 = true
```

### 5.2 Distinguir entre socket servidor y clientes (Línea 86-87)

```cpp
int fd = fds[i].fd;
if (fd == server_fd) {
```

Si el file descriptor es el del servidor, hay **nuevas conexiones**.
Si no, es un **cliente con datos**.

### 5.3 Aceptar nuevas conexiones (Línea 88-110)

```cpp
while (true) {
    struct sockaddr_in cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    int client_fd = accept(server_fd, (struct sockaddr *)&cli_addr, &cli_len);
```

**¿Qué hace `accept()`?**

Acepta una conexión pendiente y retorna un nuevo file descriptor para comunicarse con ese cliente.

**Parámetros:**
- `server_fd`: Socket servidor
- `(struct sockaddr *)&cli_addr`: Estructura para guardar la dirección del cliente
- `&cli_len`: Tamaño de la estructura (entrada y salida)

**¿Por qué la estructura de dirección?**

`accept()` rellena `cli_addr` con la IP y puerto del cliente conectado:
```cpp
struct sockaddr_in cli_addr;
socklen_t cli_len = sizeof(cli_addr);
accept(..., (struct sockaddr *)&cli_addr, &cli_len);
// Ahora cli_addr contiene: IP:puerto del cliente
```

### 5.4 Verificar si `accept()` tuvo éxito (Línea 93)

```cpp
if (client_fd < 0) {
    if (errno == EAGAIN || errno == EWOULDBLOCK) break;
    std::cerr << "accept() failed: " << strerror(errno) << std::endl;
    break;
}
```

**¿Por qué dos errores: `EAGAIN` y `EWOULDBLOCK`?**

- `EWOULDBLOCK`: Indica "el socket está configurado para no bloqueante y no hay conexión lista"
- `EAGAIN`: En muchos sistemas es sinónimo de `EWOULDBLOCK`
- Ambos se usan para compatibilidad entre sistemas

**¿Por qué `break` cuando no hay más conexiones?**

Con `O_NONBLOCK`, `accept()` retorna:
- Éxito con un `client_fd >= 0`: Hay una conexión
- Error con `EAGAIN`/`EWOULDBLOCK`: No hay más conexiones en la cola

El `break` sale del `while (true)` interno porque no hay más conexiones que aceptar.

### 5.5 Hacer el client_fd no bloqueante (Línea 99-103)

```cpp
if (set_nonblocking(client_fd) < 0) {
    std::cerr << "fcntl() client failed: " << strerror(errno) << std::endl;
    close(client_fd);
    continue;
}
```

Cada cliente también debe tener un socket no bloqueante para poder usar `poll()`.

**¿Por qué `close(client_fd)` y `continue`?**

Si `fcntl()` falla, no podemos usar el socket, así que:
1. Cerramos el socket con `close()`
2. Continuamos con la siguiente iteración

### 5.6 Añadir el cliente a `poll()` (Línea 104-108)

```cpp
struct pollfd cp;
cp.fd = client_fd;
cp.events = POLLIN;
cp.revents = 0;
fds.push_back(cp);
```

Prepara una estructura `pollfd` para este cliente:
- `fd`: El nuevo file descriptor del cliente
- `events`: `POLLIN` (vigilar datos entrantes)
- `revents`: 0 (se rellena por `poll()`)

Luego la añade al array de vigilancia.

### 5.7 Inicializar buffer del cliente (Línea 109-111)

```cpp
buffers[client_fd] = std::string();
std::cout << "New client fd=" << client_fd << std::endl;
```

- Crea un buffer vacío para este cliente
- Imprime un mensaje de nueva conexión

---

## 6. PROCESAMIENTO DE DATOS FRAGMENTADOS (Línea 112-140)

### 6.1 Leer datos del cliente (Línea 112-116)

```cpp
char buf[1024];
ssize_t n = recv(fd, buf, sizeof(buf), 0);
if (n <= 0) {
    std::cout << "client fd=" << fd << " closed" << std::endl;
    close(fd);
```

**¿Qué hace `recv()`?**

Lee datos del socket sin bloquearse (porque es `O_NONBLOCK`).

**Parámetros:**
- `fd`: Socket cliente
- `buf`: Buffer donde guardar los datos
- `sizeof(buf)`: Máximo a leer (1024 bytes)
- `0`: Flags (0 = sin flags especiales)

**¿Qué retorna `recv()`?**

```
n > 0  : Número de bytes leídos
n == 0 : Cliente cerró la conexión (FIN de TCP)
n < 0  : Error (incluyendo EAGAIN si no hay datos)
```

**¿Por qué `if (n <= 0)`?**

Si no hay datos o el cliente cerró, hay que limpiar:

```cpp
close(fd);           // Cerrar el socket
buffers.erase(fd);   // Eliminar su buffer
fds.erase(fds.begin() + i);  // Eliminarlo de poll()
--i;                 // Ajustar el índice (porque borramos un elemento)
continue;            // Saltar al siguiente fd
```

**¿Por qué `--i`?**

Si borramos el elemento en posición `i` del array, el siguiente elemento baja de posición. Si no decrementamos `i`, saltaríamos un elemento en la próxima iteración del `for`.

```
Array: [server_fd, client1_fd, client2_fd, client3_fd]
         i=0        i=1         i=2         i=3

Borramos i=1 (client1_fd):
Array: [server_fd, client2_fd, client3_fd]
         i=0        i=1         i=2

Si NO decrementamos i, el siguiente for loop incrementa a i=2,
saltando client2_fd.
```

### 6.2 Añadir datos al buffer (Línea 122)

```cpp
buffers[fd].append(buf, n);
```

**El corazón de la gestión de fragmentos:**

Cada cliente tiene un `std::string` buffer. Cuando llegan datos (aunque sean fragmentados), se añaden al buffer:

```
Cliente envía: "com"
buffers[fd] = "com"

Cliente envía: "man"
buffers[fd] = "com" + "man" = "comman"

Cliente envía: "d\n"
buffers[fd] = "comman" + "d\n" = "command\n"
```

### 6.3 Procesar líneas completas (Línea 125-139)

```cpp
size_t pos;
while ((pos = buffers[fd].find('\n')) != std::string::npos) {
    std::string line = buffers[fd].substr(0, pos);
    if (!line.empty() && line[line.size() - 1] == '\r')
        line.erase(line.size() - 1);
    line += '\n';
    ssize_t sent = send(fd, line.c_str(), line.size(), 0);
    if (sent < 0) {
        std::cerr << "send() failed: " << strerror(errno) << std::endl;
    }
    buffers[fd].erase(0, pos + 1);
}
```

**Paso 1: Buscar '\n' (Línea 126)**

```cpp
while ((pos = buffers[fd].find('\n')) != std::string::npos) {
```

- `find('\n')`: Busca la primera ocurrencia de '\n'
- `std::string::npos`: Valor especial que significa "no encontrado" (~0)
- **Mientras encuentre un '\n', continúa el bucle**

**¿Por qué un bucle `while`?**

Puede haber múltiples líneas en el buffer:

```
buffers[fd] = "comando1\ncomando2\ncomando3"
              ↑pos=8    ↑pos=17

Iteración 1: Procesa "comando1", pos=8
Iteración 2: Procesa "comando2", pos=17
Iteración 3: Procesa "comando3", sin '\n'
```

**Paso 2: Extraer la línea (Línea 127)**

```cpp
std::string line = buffers[fd].substr(0, pos);
```

- `substr(0, pos)`: Extrae desde posición 0 hasta `pos` (sin incluir `pos`)
- Ejemplo: Si `pos=7` en "command\n", retorna "command"

**Paso 3: Eliminar '\r' si existe (CRLF) (Línea 128-129)**

```cpp
if (!line.empty() && line[line.size() - 1] == '\r')
    line.erase(line.size() - 1);
```

Los clientes IRC pueden enviar "\r\n" (CRLF) en lugar de sólo "\n":

```
Cliente envía: "command\r\n"
Después de substr(0, pos): line = "command\r"
Aquí eliminamos la '\r' final: line = "command"
```

**Paso 4: Hacer echo (Línea 130)**

```cpp
line += '\n';
```

Añade un '\n' para responder con una línea completa.

**Paso 5: Enviar respuesta (Línea 131-134)**

```cpp
ssize_t sent = send(fd, line.c_str(), line.size(), 0);
if (sent < 0) {
    std::cerr << "send() failed: " << strerror(errno) << std::endl;
}
```

- `send()`: Envía datos al cliente (no bloqueante)
- `line.c_str()`: Puntero al contenido de la línea
- `line.size()`: Número de bytes a enviar

**¿Por qué no verificamos `sent == line.size()`?**

Con `O_NONBLOCK`, `send()` podría no enviar todos los bytes. Para un servidor robusto, habría que:
1. Guardar datos no enviados en otro buffer
2. Usar `poll()` con `POLLOUT` para saber cuándo puede escribir más

Para este ejemplo mínimo, ignoramos este escenario.

**Paso 6: Eliminar la línea procesada del buffer (Línea 135)**

```cpp
buffers[fd].erase(0, pos + 1);
```

- `erase(0, pos + 1)`: Elimina desde posición 0 hasta `pos + 1` (incluye el '\n')

**Ejemplo completo:**

```
buffers[fd] = "command\nmore_data"
pos = 7 (posición del '\n')

Procesamos: "command"
Hacemos echo: "command\n"

buffers[fd].erase(0, 7 + 1)
= buffers[fd].erase(0, 8)
= "more_data"
```

---

## 7. CIERRE DE CONEXIONES (Línea 141-149)

```cpp
if (fds[i].revents & (POLLHUP | POLLERR)) {
    int fd = fds[i].fd;
    std::cout << "client fd=" << fd << " hung up or error" << std::endl;
    close(fd);
    buffers.erase(fd);
    fds.erase(fds.begin() + i);
    --i;
}
```

**¿Qué son `POLLHUP` y `POLLERR`?**

| Flag | Significado |
|------|-------------|
| `POLLHUP` | El cliente cerró la conexión (TCP FIN) |
| `POLLERR` | Hubo un error en el socket |

**¿Por qué después de verificar POLLIN?**

Porque dentro del `if (fds[i].revents & POLLIN)` ya manejamos desconexiones con `recv()`. Pero hay casos donde:
1. El cliente se desconecta sin que haya dato para leer
2. Hay un error en el socket

Este bloque adicional captura esos casos.

### 7.1 Limpieza (Línea 162-163)

```cpp
for (size_t i = 0; i < fds.size(); ++i) close(fds[i].fd);
return 0;
```

Cuando se sale del bucle `while (true)`:
1. Cierra todos los sockets abiertos
2. Retorna 0 (éxito)

---

## DIAGRAMA DE FLUJO COMPLETO

```
┌─────────────────────────────────────────┐
│ INICIO: Crear socket, bind(), listen()  │
└──────────────┬──────────────────────────┘
               │
               ▼
┌──────────────────────────────────────────────┐
│ BUCLE PRINCIPAL                              │
│ ┌────────────────────────────────────────┐   │
│ │ poll() - Esperar eventos               │   │
│ └───┬───────────────────────────────────┬┘   │
│     │                                   │    │
│     ▼                                   ▼    │
│ ┌──────────────────┐          ┌──────────────┐
│ │ Server socket    │          │ Cliente      │
│ │ (POLLIN)         │          │ sockets      │
│ └──────┬───────────┘          └──────┬───────┘
│        │                             │
│        ▼                             ▼
│ ┌──────────────────────┐   ┌─────────────────────┐
│ │ accept() - Nueva     │   │ recv() - Leer datos │
│ │ conexión             │   └────┬────────────────┘
│ ├──────────────────────┤        │
│ │ • Crear client_fd    │        ▼
│ │ • O_NONBLOCK         │   ┌────────────────────────┐
│ │ • Añadir a poll()    │   │ Append a buffer[fd]    │
│ │ • Buffer vacío       │   └────┬───────────────────┘
│ └──────────────────────┘        │
│                                 ▼
│                         ┌────────────────────────┐
│                         │ ¿Hay '\n' en buffer?   │
│                         └────┬───────────────────┘
│                              │
│                       ┌──────┴──────┐
│                       ▼             ▼
│                      SÍ             NO
│                       │         Esperar +datos
│                       ▼
│                   ┌─────────────────┐
│                   │ Extraer línea   │
│                   │ Hacer echo      │
│                   │ send()          │
│                   │ Actualizar buf  │
│                   └─────────────────┘
│
└──────────────────────────────────────────────┘
```

---

## EJEMPLO DE EJECUCIÓN

### Terminal 1 (Servidor):
```bash
$ ./mini_irc_test 6667
mini_irc_test listening on 0.0.0.0:6667
New client fd=4
New client fd=5
client fd=4 closed
```

### Terminal 2 (Cliente 1):
```bash
$ nc -C 127.0.0.1 6667
hello
hello
world
world
^C
```

### Terminal 3 (Cliente 2):
```bash
$ nc -C 127.0.0.1 6667
testing
testing
fragments: com^D man^D d
fragments: command
^C
```

---

## VENTAJAS DE ESTE DISEÑO

| Aspecto | Ventaja |
|---------|---------|
| **No bloqueante** | Múltiples clientes sin hilos |
| **poll()** | Eficiente, compatible con POSIX |
| **Buffer por cliente** | Maneja fragmentos correctamente |
| **Limpieza explícita** | Controla recursos manualmente |
| **C++98** | Compatible con compiladores antiguos |

---

## LIMITACIONES Y MEJORAS FUTURAS

| Limitación | Solución |
|-----------|----------|
| **Buffer de recepción fijo (1024 bytes)** | Aumentar o hacer dinámico |
| **No gestiona POLLOUT** | Puede perder datos enviados |
| **Sin timeout en poll()** | Servidor responde lentamente a Ctrl+C |
| **Limpieza en `n <= 0`** | Algunos errores no se manejan bien |
| **Sin protección de multi-hilo** | No es problemático si `poll()` es único |

