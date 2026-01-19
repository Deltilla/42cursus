# IRC Server - Proyecto Base C++98

Este proyecto implementa la base de un servidor IRC compatible con el subject **ircserv**, cumpliendo estrictamente los requisitos de C++98 y gestión de comandos fragmentados.

## 📋 Características

- ✅ **Servidor no-bloqueante** usando `poll()` para multiplexación
- ✅ **Manejo de fragmentos**: Acumula datos en buffer por cliente hasta detectar `\n`
- ✅ **C++98 puro**: Sin `auto`, `nullptr`, hilos ni contenedores C++11
- ✅ **Cumplimiento de flags**: `-Wall -Wextra -Werror -std=c++98`
- ✅ **Gestión robusta de errores** con mensajes a `std::cerr`
- ✅ **Soporte CRLF**: Maneja tanto `\n` como `\r\n`

## 🏗️ Estructura

```
irc_test/
├── Makefile                    # Targets: all, clean, fclean, re
├── mini_irc_test.cpp          # Servidor de sandbox (single-file, ~180 líneas)
├── test_fragments.sh          # Script de pruebas automatizadas
├── FRAGMENTOS_EXPLICACION.md  # Documentación detallada del flujo
│
├── includes/
│   ├── Server.hpp       # Gestión del servidor y poll()
│   ├── Client.hpp       # Buffer y métodos de línea
│   └── Channel.hpp      # Estructura básica de canal
│
└── srcs/
    ├── main.cpp         # Punto de entrada: ./ircserv <port> <password>
    ├── Server.cpp       # Implementación del servidor
    ├── Client.cpp       # Buffer: appendToBuffer(), popLine()
    └── Channel.cpp      # Base para canales
```

## 🚀 Compilación

```bash
# Compilar todo
make

# Compilar solo el servidor principal
make ircserv

# Compilar solo el sandbox
make mini_irc_test

# Limpiar objetos
make clean

# Limpiar todo (incluye binarios)
make fclean

# Recompilar desde cero
make re
```

## 🧪 Pruebas

### Opción 1: Script automático
```bash
./test_fragments.sh
```
Realiza 3 pruebas de fragmentación automáticamente.

### Opción 2: Sandbox manual
```bash
# Terminal 1
./mini_irc_test 6667

# Terminal 2
nc -C 127.0.0.1 6667
```

Escribe fragmentado con `Ctrl+D`:
```
com<Ctrl+D>man<Ctrl+D>d<Enter>
// Devuelve: command
```

### Opción 3: Servidor principal
```bash
# Terminal 1
./ircserv 6667 mypassword

# Terminal 2
nc 127.0.0.1 6667
```

## 📡 Cómo Funciona el Buffer

**Problema**: Los datos llegan fragmentados en múltiples paquetes TCP.

**Solución**: Mantener un buffer `std::string` por cliente que acumula datos hasta detectar `\n`.

```cpp
// Flujo simplificado
recv(fd, buf, 1024)        // Recibe "com"
client->appendToBuffer("com", 3)
// buffer = "com"

recv(fd, buf, 1024)        // Recibe "man"
client->appendToBuffer("man", 3)
// buffer = "coman"

recv(fd, buf, 1024)        // Recibe "d\n"
client->appendToBuffer("d\n", 2)
// buffer = "command\n"

while (client->popLine(cmd)) {
    // cmd = "command"
    // Procesar comando completo
    // buffer queda vacío
}
```

Consulta [FRAGMENTOS_EXPLICACION.md](FRAGMENTOS_EXPLICACION.md) para una explicación detallada.

## 🔧 APIs Usadas

Todas autorizadas por el subject:

| Función | Propósito |
|---------|-----------|
| `socket()` | Crear socket |
| `bind()` | Enlazar puerto |
| `listen()` | Aceptar conexiones |
| `accept()` | Aceptar cliente |
| `poll()` | Multiplexar I/O |
| `fcntl()` | No-bloqueo (O_NONBLOCK) |
| `recv()` | Leer datos |
| `send()` | Escribir datos |
| `close()` | Cerrar socket |
| `setsockopt()` | SO_REUSEADDR |

## 📊 Ejemplo: Test de Fragmentación

Entrada:
```
nc -C 127.0.0.1 6667
com<Ctrl+D>man<Ctrl+D>d<Enter>
```

Salida esperada:
```
command
```

**Lo que sucede internamente**:
1. `recv()` lee "com" → buffer = "com"
2. `recv()` lee "man" → buffer = "coman"
3. `recv()` lee "d\n" → buffer = "command\n"
4. `popLine()` detecta `\n` → extrae "command" y procesa

## 🛡️ Validaciones C++98

- ❌ No hay `auto`, `nullptr`, `constexpr`, `nullptr_t`
- ❌ No hay hilos (`std::thread`, `std::mutex`)
- ❌ No hay contenedores STL de C++11 (`unordered_map`, etc.)
- ❌ Solo `std::string`, `std::vector`, `std::map`
- ✅ Headers C++ (`<cstring>` en lugar de `<string.h>`)
- ✅ Compilación con `-std=c++98` exitosa

## 📝 Líneas de Código

```
mini_irc_test.cpp    ~180 líneas  (servidor sandbox completo)
Server.cpp           ~150 líneas  (servidor principal)
Client.cpp           ~30 líneas   (buffer management)
Channel.cpp          ~25 líneas   (base para canales)
Total                ~385 líneas  (sin contar headers)
```

## 🎯 Próximos Pasos para Implementación Completa

1. **Autenticación**: Comando `PASS`
2. **Identificación**: Comandos `NICK` y `USER`
3. **Canales**: Comando `JOIN`, `LEAVE`
4. **Mensajería**: `PRIVMSG`, `NOTICE`
5. **Operadores**: `KICK`, `INVITE`, `TOPIC`, `MODE`
6. **Modo canal**: `-i`, `-t`, `-k`, `-o`, `-l`

## 🔍 Depuración

Los logs se imprimen a `std::cout`:
```
Server listening on 0.0.0.0:6667
New client fd=4
Client 4 sent: [command]
Closing client fd=4
```

Los errores van a `std::cerr`:
```
socket() failed: Address already in use
poll() failed: No such file or directory
```

## 📦 Dependencias

- `<sys/socket.h>`, `<netinet/in.h>` - Sockets POSIX
- `<poll.h>` - Multiplexación
- `<fcntl.h>` - Control de opciones
- `<unistd.h>` - APIs POSIX
- `<string>`, `<vector>`, `<map>` - STL C++98

Todo disponible en sistemas UNIX/Linux estándar.

## 📄 Licencia

Proyecto educativo para el subject ircserv.
