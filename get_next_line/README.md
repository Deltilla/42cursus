# get_next_line

## 🇬🇧 English Version | [Leer en español 🇪🇸↓](#acerca-de-get_next_line)

### About get_next_line

**get_next_line** is a project focused on reading a line from a file descriptor. The challenge is to handle reading efficiently, managing static variables, and dealing with different buffer sizes. This function is essential for reading files line by line and is used in many future projects.

### Project Objectives

- Implement a function that reads a line from a file descriptor
- Handle multiple file descriptors simultaneously (bonus)
- Understand and use static variables
- Manage dynamic memory allocation efficiently
- Deal with various buffer sizes set at compilation

### Function Prototype

```c
char *get_next_line(int fd);
```

### Features

- Reads from file descriptor one line at a time
- Returns the line including the newline character `\n`
- Returns `NULL` when reaching end of file or on error
- Works with files, standard input, and other file descriptors
- Bonus: Can handle multiple file descriptors at the same time

### Compilation

The function can be compiled with different buffer sizes:

```bash
gcc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

### Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

***

## 🇪🇸 Versión en Español | [Read in English 🇬🇧↑](#about-get_next_line)

### Acerca de get_next_line

**get_next_line** es un proyecto centrado en leer una línea desde un descriptor de archivo. El desafío es manejar la lectura de manera eficiente, gestionar variables estáticas y tratar con diferentes tamaños de búfer. Esta función es esencial para leer archivos línea por línea y se utiliza en muchos proyectos futuros.

### Objetivos del Proyecto

- Implementar una función que lee una línea desde un descriptor de archivo
- Manejar múltiples descriptores de archivo simultáneamente (bonus)
- Comprender y usar variables estáticas
- Gestionar la asignación de memoria dinámica de manera eficiente
- Trabajar con varios tamaños de búfer establecidos en la compilación

### Prototipo de la Función

```c
char *get_next_line(int fd);
```

### Características

- Lee del descriptor de archivo una línea a la vez
- Devuelve la línea incluyendo el carácter de nueva línea `\n`
- Devuelve `NULL` al alcanzar el final del archivo o en caso de error
- Funciona con archivos, entrada estándar y otros descriptores de archivo
- Bonus: Puede manejar múltiples descriptores de archivo al mismo tiempo

### Compilación

La función puede compilarse con diferentes tamaños de búfer:

```bash
gcc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

### Ejemplo de Uso

```c
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("archivo.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```
