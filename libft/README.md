# Libft

## 🇬🇧 English Version | [Leer en español 🇪🇸↓](#acerca-de-libft)

### About Libft

**Libft** is the first project in the 42cursus curriculum. The goal of this project is to recreate several standard C library functions, gaining a deep understanding of how they work internally. This custom library serves as a foundation for future projects throughout the curriculum.

### Project Objectives

- Implement basic C library functions from scratch
- Understand memory manipulation and string handling
- Learn to create and manage a static library
- Master pointer manipulation and memory allocation

### Functions Implemented

The library includes implementations of:
- **Character checks**: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- **String manipulation**: `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strlcpy`, `ft_strlcat`, `ft_strnstr`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_striteri`, `ft_strmapi`
- **Memory functions**: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- **Conversion**: `ft_atoi`, `ft_itoa`, `ft_toupper`, `ft_tolower`
- **Output**: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- **Linked lists (bonus)**: `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

### Compilation

```bash
make        # Compile the library
make bonus  # Compile with bonus functions
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Recompile everything
```

***

## 🇪🇸 Versión en Español | [Read in English 🇬🇧↑](#about-libft)

### Acerca de Libft

**Libft** es el primer proyecto del currículo de 42cursus. El objetivo de este proyecto es recrear varias funciones de la biblioteca estándar de C, obteniendo un profundo entendimiento de cómo funcionan internamente. Esta biblioteca personalizada sirve como base para futuros proyectos a lo largo del currículo.

### Objetivos del Proyecto

- Implementar funciones básicas de la biblioteca de C desde cero
- Comprender la manipulación de memoria y el manejo de cadenas
- Aprender a crear y gestionar una biblioteca estática
- Dominar la manipulación de punteros y la asignación de memoria

### Funciones Implementadas

La biblioteca incluye implementaciones de:
- **Verificación de caracteres**: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- **Manipulación de cadenas**: `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strlcpy`, `ft_strlcat`, `ft_strnstr`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_striteri`, `ft_strmapi`
- **Funciones de memoria**: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- **Conversión**: `ft_atoi`, `ft_itoa`, `ft_toupper`, `ft_tolower`
- **Salida**: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- **Listas enlazadas (bonus)**: `ft_lstnew`, `ft_lstadd_front`, `ft_lstadd_back`, `ft_lstsize`, `ft_lstlast`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

### Compilación

```bash
make        # Compilar la biblioteca
make bonus  # Compilar con funciones bonus
make clean  # Eliminar archivos objeto
make fclean # Eliminar archivos objeto y biblioteca
make re     # Recompilar todo
```
