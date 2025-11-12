# Pipex

## 🇬🇧 English Version | [Leer en español 🇪🇸↓](#acerca-de-pipex)

### About Pipex

**Pipex** is a project that introduces process creation and inter-process communication in UNIX systems. The program mimics the behavior of shell pipes, allowing the chaining of commands. This project teaches fundamental concepts about process management, file descriptors, and pipes.

### Project Objectives

- Understand and use `fork()` to create child processes
- Learn about process communication through pipes
- Handle file descriptors and redirection
- Execute external commands using `execve()`
- Master the UNIX pipe mechanism (`|`)

### Program Behavior

The program simulates the following shell command:
```bash
< file1 cmd1 | cmd2 > file2
```

This is equivalent to:
```bash
./pipex file1 cmd1 cmd2 file2
```

### Features

- Reads input from `file1`
- Executes `cmd1` with `file1` as input
- Pipes the output of `cmd1` to `cmd2`
- Writes the output of `cmd2` to `file2`
- Handles errors and edge cases
- Bonus: Supports multiple pipes and here_doc

### Compilation

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

### Usage Example

```bash
./pipex infile "ls -l" "wc -l" outfile
# Equivalent to: < infile ls -l | wc -l > outfile
```

***

## 🇪🇸 Versión en Español | [Read in English 🇬🇧↑](#about-pipex)

### Acerca de Pipex

**Pipex** es un proyecto que introduce la creación de procesos y la comunicación entre procesos en sistemas UNIX. El programa imita el comportamiento de las tuberías (pipes) del shell, permitiendo el encadenamiento de comandos. Este proyecto enseña conceptos fundamentales sobre gestión de procesos, descriptores de archivo y tuberías.

### Objetivos del Proyecto

- Comprender y usar `fork()` para crear procesos hijos
- Aprender sobre comunicación entre procesos a través de tuberías
- Manejar descriptores de archivo y redirección
- Ejecutar comandos externos usando `execve()`
- Dominar el mecanismo de tuberías de UNIX (`|`)

### Comportamiento del Programa

El programa simula el siguiente comando de shell:
```bash
< archivo1 cmd1 | cmd2 > archivo2
```

Esto es equivalente a:
```bash
./pipex archivo1 cmd1 cmd2 archivo2
```

### Características

- Lee entrada desde `archivo1`
- Ejecuta `cmd1` con `archivo1` como entrada
- Conecta la salida de `cmd1` con `cmd2` mediante una tubería
- Escribe la salida de `cmd2` en `archivo2`
- Maneja errores y casos extremos
- Bonus: Soporta múltiples tuberías y here_doc

### Compilación

```bash
make        # Compilar el programa
make clean  # Eliminar archivos objeto
make fclean # Eliminar archivos objeto y ejecutable
make re     # Recompilar todo
```

### Ejemplo de Uso

```bash
./pipex archivo_entrada "ls -l" "wc -l" archivo_salida
# Equivalente a: < archivo_entrada ls -l | wc -l > archivo_salida
```
