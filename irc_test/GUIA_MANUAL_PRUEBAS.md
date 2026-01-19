# Guía de Uso - Manual de Pruebas

## 🎯 Objetivo

Demostrar el manejo correcto de comandos fragmentados usando el método del buffer por cliente.

## 1️⃣ Prueba Rápida (sin script)

### Paso 1: Compilar
```bash
cd /home/deltilla/projects/irc_test
make
```

Esperado:
```
c++ -Wall -Wextra -Werror -std=c++98 -I includes -c srcs/Server.cpp -o srcs/Server.o
c++ -Wall -Wextra -Werror -std=c++98 -I includes -c srcs/Client.cpp -o srcs/Client.o
c++ -Wall -Wextra -Werror -std=c++98 -I includes -c srcs/Channel.cpp -o srcs/Channel.o
c++ -Wall -Wextra -Werror -std=c++98 -I includes -c srcs/main.cpp -o srcs/main.o
c++ -Wall -Wextra -Werror -std=c++98 -I includes -o ircserv srcs/Server.o ...
c++ -Wall -Wextra -Werror -std=c++98 -o mini_irc_test mini_irc_test.cpp
```

### Paso 2: Iniciar servidor sandbox
```bash
./mini_irc_test 6667
```

Esperado:
```
mini_irc_test listening on 0.0.0.0:6667
```

### Paso 3: Conectar con netcat (en otra terminal)
```bash
nc -C 127.0.0.1 6667
```

### Paso 4: Enviar comando fragmentado
Escribe "com", luego **Ctrl+D**, luego "man", luego **Ctrl+D**, luego "d" y presiona **Enter**:

```
com^Dman^Dd
```

Esperado - El servidor devuelve (echo):
```
command
```

La conexión se cierra y ves en el servidor:
```
New client fd=4
command
client fd=4 closed
```

---

## 2️⃣ Prueba con Script Automatizado

```bash
./test_fragments.sh
```

Ejecuta 3 pruebas:
- **Prueba 1**: Fragmentación simple (com + man + d)
- **Prueba 2**: Múltiples comandos en una conexión
- **Prueba 3**: Fragmentación con salto de línea en el medio

Salida esperada:
```
======================================
Test: Manejo de Fragmentos en IRC
======================================

[1] Compilando servidores...
✅ Compilación exitosa

[2] Iniciando mini_irc_test en puerto 6667...
mini_irc_test listening on 0.0.0.0:6667
✅ Servidor iniciado (PID=XXXXX)

[3] Prueba 1: Comando fragmentado (com + man + d)

New client fd=4
command
client fd=4 closed

[4] Prueba 2: Múltiples comandos en una sola conexión

New client fd=4
hello
world
client fd=4 closed

[5] Prueba 3: Fragmentación con salto de línea en el medio

New client fd=4
line1
line2
client fd=4 closed

======================================
✅ Pruebas completadas
======================================
```

---

## 3️⃣ Prueba Manual Avanzada

### Caso 1: Enviar datos muy fragmentados

```bash
# Terminal 1
./mini_irc_test 6667

# Terminal 2
nc -C 127.0.0.1 6667
```

Escribe carácter por carácter con `sleep`:
```bash
{
    printf "A"
    sleep 1
    printf "B"
    sleep 1
    printf "C"
    sleep 1
    printf "\n"
    sleep 0.2
} | nc -q 1 127.0.0.1 6667
```

Esperado: El servidor recibe y devuelve "ABC".

### Caso 2: Múltiples líneas consecutivas

```bash
{
    printf "line1\nline2\nline3\n"
    sleep 0.2
} | nc -q 1 127.0.0.1 6667
```

Esperado:
```
line1
line2
line3
```

### Caso 3: Línea incompleta (sin \n)

```bash
{
    printf "incomplete"
    sleep 0.5
    printf "command\n"
    sleep 0.2
} | nc -q 1 127.0.0.1 6667
```

Esperado:
```
incompletecommand
```

### Caso 4: CRLF (carriage return + line feed)

```bash
{
    printf "hello\r\n"
    sleep 0.2
} | nc -C 127.0.0.1 6667
```

Esperado (el servidor limpia el \r):
```
hello
```

---

## 🔍 Cómo Ver los Logs del Servidor

En el terminal donde corre el servidor ves automáticamente:

```
New client fd=4              # Conexión aceptada
Client 4 sent: [command]    # Comando recibido
Closing client fd=4         # Cliente desconectado
```

---

## 🧩 Flujo Interno (Conceptual)

Cuando escribes "com**[Ctrl+D]**man**[Ctrl+D]**d**[Enter]**":

```
1. Cliente: envía "com" (EOF)
   Servidor: recv() -> "com"
   Buffer del cliente: "com"
   ¿Hay \n? NO
   
2. Cliente: envía "man" (EOF)
   Servidor: recv() -> "man"
   Buffer del cliente: "comman"
   ¿Hay \n? NO
   
3. Cliente: envía "d\n"
   Servidor: recv() -> "d\n"
   Buffer del cliente: "command\n"
   ¿Hay \n? SÍ
   popLine() extrae: "command"
   Buffer queda: ""
   Procesar "command"
```

---

## 📊 Verificación: ¿Funciona Correctamente?

✅ **Sí, si**:
- El servidor compila con `make` sin errores
- Puedes conectar con `nc 127.0.0.1 6667`
- Envías "com**[Ctrl+D]**man**[Ctrl+D]**d**[Enter]**" y recibes "command"
- El script `test_fragments.sh` muestra "✅ Pruebas completadas"

❌ **No, si**:
- El servidor no compila (revisar flags C++98)
- `nc` se cuelga sin respuesta
- Envías fragmentado y no recibes nada de vuelta
- El script falla en algún test

---

## 🚨 Troubleshooting

| Problema | Solución |
|----------|----------|
| "Address already in use" | Cambiar puerto: `./mini_irc_test 6668` |
| `nc` no devuelve respuesta | Verificar que el servidor está en escucha. Presionar **Enter** después del último fragmento. |
| Compilación falla | Verificar que estás en `/home/deltilla/projects/irc_test`. Ejecutar `make clean` y `make`. |
| Script no ejecutable | `chmod +x test_fragments.sh` |
| No ves logs del servidor | Asegúrate de que el servidor no se lanzó en background. |

---

## 📋 Checklist de Validación

- [ ] `make` compila sin errores (flags: -Wall -Wextra -Werror -std=c++98)
- [ ] Servidor sandbox: `./mini_irc_test 6667` inicia sin crashes
- [ ] Prueba fragmentos: "com+man+d" → recibe "command"
- [ ] Prueba múltiples comandos: "hello\nworld" → recibe ambos
- [ ] Prueba CRLF: servidor no incluye \r en el output
- [ ] Script test: `./test_fragments.sh` pasa sin errores
- [ ] No hay memory leaks visibles (valgrind opcional)
- [ ] Compilación C++98 estricta: `-std=c++98`

---

## 💡 Notas

- El servidor no implementa lógica IRC real aún (solo echo).
- El buffer es `std::string` (C++98, sin `std::vector<char>`).
- Se usa `poll()` exclusivamente (no select, no epoll).
- No hay hilos: todo es secuencial no-bloqueante.

Consulta `FRAGMENTOS_EXPLICACION.md` para entender en profundidad el código.
