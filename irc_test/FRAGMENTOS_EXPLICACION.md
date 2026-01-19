# IRC Server - Explicación del Flujo de Comandos Fragmentados

## 📋 Resumen del Problema

El subject del ircserv exige que el servidor maneje correctamente **comandos que llegan fragmentados** en múltiples paquetes TCP.

### Test Example del Subject
```bash
$ nc -C 127.0.0.1 6667
com^Dman^Dd
$ 
```
Usando `Ctrl+D`, se envía:
1. "com"
2. "man"
3. "d\n"

El servidor debe recibir estos fragmentos y reconocer "command\n" como un comando completo.

---

## 🔄 Arquitectura: Buffer por Cliente

### Flujo Conceptual

```
Cliente                          Servidor
  |                                |
  |------- "com" -------->         |
  |                           (append to buffer)
  |                           buffer = "com"
  |------- "man" ------>          |
  |                           (append to buffer)
  |                           buffer = "com" + "man" = "coman"
  |------- "d\n" -------->         |
  |                           (append to buffer)
  |                           buffer = "coman" + "d\n" = "command\n"
  |                           (detect '\n' -> extract "command")
  |<------ COMMAND PROCESADO ------
```

### Implementación en C++98

**Cliente.hpp** define el buffer y el método de extracción:

```cpp
class Client {
  private:
    std::string _buffer;  // Acumula datos fragmentados
  public:
    void appendToBuffer(const char *data, size_t len);
    bool popLine(std::string &out);  // Extrae primera línea si existe '\n'
};
```

**Cliente.cpp** implementa la lógica:

```cpp
void Client::appendToBuffer(const char *data, size_t len) {
    _buffer.append(data, len);  // Añadir datos recibidos
}

bool Client::popLine(std::string &out) {
    size_t pos = _buffer.find('\n');  // Buscar delimitador
    if (pos == std::string::npos)
        return false;  // Aún no hay línea completa
    
    out = _buffer.substr(0, pos);  // Extraer hasta '\n'
    
    // Soportar CRLF (eliminar '\r' si existe)
    if (!out.empty() && out[out.size() - 1] == '\r')
        out.erase(out.size() - 1);
    
    _buffer.erase(0, pos + 1);  // Borrar del buffer
    return true;  // Línea extraída
}
```

---

## 📡 Server::handleClientData - Integración con poll()

En `Server::run()`, el bucle de poll() maneja múltiples clientes:

```cpp
void Server::handleClientData(int fd) {
    if (_clients.find(fd) == _clients.end()) return;

    Client *client = _clients[fd];
    char buf[1024];
    ssize_t n = recv(fd, buf, sizeof(buf), 0);
    if (n <= 0) {
        removeClient(fd);  // Conexión cerrada
        return;
    }

    // 1. Acumular datos en el buffer del cliente
    client->appendToBuffer(buf, n);

    // 2. Extraer todas las líneas completas disponibles
    std::string cmd;
    while (client->popLine(cmd)) {
        // Procesar comando completo 'cmd'
        // Por ahora, echo para pruebas
        cmd += "\r\n";
        send(fd, cmd.c_str(), cmd.size(), 0);
    }
    // Si no hay '\n', la data fragmentada queda en buffer hasta próxima lectura
}
```

### Ejemplo de Ejecución paso a paso:

```
[1] recv(fd) -> "com"
    client->appendToBuffer("com", 3)
    buffer = "com"
    popLine() -> false (no '\n')

[2] recv(fd) -> "man"
    client->appendToBuffer("man", 3)
    buffer = "comman"
    popLine() -> false (no '\n')

[3] recv(fd) -> "d\n"
    client->appendToBuffer("d\n", 2)
    buffer = "command\n"
    popLine() -> true, cmd = "command"
    buffer = "" (vaciado)
    Procesar "command"
```

---

## 🧪 Pruebas

### Con mini_irc_test (servidor de sandbox)

```bash
# Terminal 1: iniciar servidor
$ ./mini_irc_test 6667
mini_irc_test listening on 0.0.0.0:6667

# Terminal 2: conectar cliente
$ nc -C 127.0.0.1 6667

# Escribir fragmentado (Ctrl+D entre cada fragmento)
hello
hello          # Echo inmediato

com
man
d
command        # Devuelve completo cuando detecta '\n'
```

### Con ircserv (servidor principal)

```bash
$ ./ircserv 6667 mypass
Server listening on 0.0.0.0:6667

$ nc -C 127.0.0.1 6667
# Enviar fragmentado
PASS my^Dpa^Dss
PASS mypass    # Echo de prueba

NICK nick^Dnam^De
NICK nickname  # Echo cuando llega completo
```

---

## 🛡️ Ventajas de este Diseño

1. **Maneja fragmentación**: datos que llegan en múltiples recv()
2. **Soporta múltiples comandos en una lectura**: si el cliente envía "CMD1\nCMD2\n", ambos se extraen
3. **No bloqueante**: poll() solo procesa cuando hay datos listos
4. **Memoria predecible**: buffer por cliente (C++98, sin contenedores dinámicos)
5. **Cumple subject**: usa SOLO funciones autorizadas (socket, poll, fcntl, recv, send)

---

## 📝 Restricciones C++98 Cumplidas

✅ Sin `auto`  
✅ Sin `nullptr` (usamos `0`)  
✅ Sin hilos (solo poll + no-bloqueo)  
✅ Sin contenedores STL de C++11  
✅ Flags: `-Wall -Wextra -Werror -std=c++98`  
✅ Headers C++ no C (`<cstring>` en lugar de `<string.h>`)  
✅ Solo funciones autorizadas

---

## 📂 Estructura del Proyecto

```
irc_test/
├── Makefile              # Targets: all, clean, fclean, re
├── mini_irc_test.cpp     # Sandbox completo (single-file)
├── includes/
│   ├── Server.hpp
│   ├── Client.hpp        # Con métodos de buffer
│   └── Channel.hpp
└── srcs/
    ├── main.cpp          # ./ircserv <port> <password>
    ├── Server.cpp        # run() + poll() + handleClientData
    ├── Client.cpp        # appendToBuffer() + popLine()
    └── Channel.cpp
```

---

## 🎯 Próximos Pasos

1. ✅ Manejo de fragmentos (hecho)
2. ⬜ Implementar comandos IRC (PASS, NICK, USER, etc.)
3. ⬜ Gestión de canales y usuarios
4. ⬜ Operadores y modos de canal
5. ⬜ Private messages y broadcasting
