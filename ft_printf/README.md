# ft_printf

## 🇬🇧 English Version | [Leer en español 🇪🇸↓](#acerca-de-ft_printf)

### About ft_printf

**ft_printf** is a project that involves recreating the famous `printf` function from the C standard library. This project helps understand variadic functions, type formatting, and output management.

### Project Objectives

- Implement a variadic function that mimics `printf` behavior
- Handle different format specifiers
- Understand and work with variable arguments (`va_list`, `va_start`, `va_arg`, `va_end`)
- Manage different data types and their conversion

### Format Specifiers Implemented

- `%c` - Print a single character
- `%s` - Print a string
- `%p` - Print a pointer in hexadecimal format
- `%d` / `%i` - Print a decimal (base 10) number
- `%u` - Print an unsigned decimal number
- `%x` - Print a number in hexadecimal (base 16) lowercase format
- `%X` - Print a number in hexadecimal (base 16) uppercase format
- `%%` - Print a percent sign

### Compilation

```bash
make        # Compile the library
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Recompile everything
```

### Usage Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "World");
    ft_printf("Number: %d, Hex: %x\n", 42, 42);
    return (0);
}
```

***

## 🇪🇸 Versión en Español | [Read in English 🇬🇧↑](#about-ft_printf)

### Acerca de ft_printf

**ft_printf** es un proyecto que consiste en recrear la famosa función `printf` de la biblioteca estándar de C. Este proyecto ayuda a entender las funciones variádicas, el formateo de tipos y la gestión de salida.

### Objetivos del Proyecto

- Implementar una función variádica que imita el comportamiento de `printf`
- Manejar diferentes especificadores de formato
- Comprender y trabajar con argumentos variables (`va_list`, `va_start`, `va_arg`, `va_end`)
- Gestionar diferentes tipos de datos y su conversión

### Especificadores de Formato Implementados

- `%c` - Imprime un solo carácter
- `%s` - Imprime una cadena
- `%p` - Imprime un puntero en formato hexadecimal
- `%d` / `%i` - Imprime un número decimal (base 10)
- `%u` - Imprime un número decimal sin signo
- `%x` - Imprime un número en hexadecimal (base 16) en minúsculas
- `%X` - Imprime un número en hexadecimal (base 16) en mayúsculas
- `%%` - Imprime un signo de porcentaje

### Compilación

```bash
make        # Compilar la biblioteca
make clean  # Eliminar archivos objeto
make fclean # Eliminar archivos objeto y biblioteca
make re     # Recompilar todo
```

### Ejemplo de Uso

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hola %s!\n", "Mundo");
    ft_printf("Número: %d, Hex: %x\n", 42, 42);
    return (0);
}
```
