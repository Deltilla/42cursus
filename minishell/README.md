# Minishell

## 🇬🇧 English Version | [Leer en español 🇪🇸↓](#acerca-de-minishell)

### About Minishell

**Minishell** is one of the most complex projects in the 42cursus common core. The goal is to create a simple shell similar to bash, implementing command parsing, execution, pipes, redirections, and environment variable management.

### Project Objectives

- Understand how a shell works internally
- Implement command parsing and lexical analysis
- Handle process creation and execution
- Manage pipes and redirections
- Work with environment variables
- Implement built-in commands
- Handle signals properly (Ctrl-C, Ctrl-D, Ctrl-\)

### Features Implemented

#### Built-in Commands
- `echo` with option `-n`
- `cd` with relative or absolute path
- `pwd` without options
- `export` without options
- `unset` without options
- `env` without options or arguments
- `exit` without options

#### Shell Features
- Command history
- Single quotes (`'`) and double quotes (`"`)
- Redirections:
  - `<` redirect input
  - `>` redirect output
  - `<<` here_doc
  - `>>` append output
- Pipes (`|`)
- Environment variables (`$VAR`)
- Exit status (`$?`)
- Signal handling (Ctrl-C, Ctrl-D, Ctrl-\)

### Compilation

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

### Usage

```bash
./minishell
# Opens the shell prompt where you can execute commands
```

### Example Commands

```bash
minishell$ echo "Hello World"
minishell$ ls -la | grep minishell
minishell$ cat < input.txt | wc -l > output.txt
minishell$ export PATH=/usr/bin:/bin
minishell$ cd ..
```

***

## 🇪🇸 Versión en Español | [Read in English 🇬🇧↑](#about-minishell)

### Acerca de Minishell

**Minishell** es uno de los proyectos más complejos del núcleo común de 42cursus. El objetivo es crear un shell simple similar a bash, implementando análisis de comandos, ejecución, tuberías, redirecciones y gestión de variables de entorno.

### Objetivos del Proyecto

- Comprender cómo funciona un shell internamente
- Implementar análisis de comandos y análisis léxico
- Manejar creación y ejecución de procesos
- Gestionar tuberías y redirecciones
- Trabajar con variables de entorno
- Implementar comandos integrados
- Manejar señales correctamente (Ctrl-C, Ctrl-D, Ctrl-\)

### Características Implementadas

#### Comandos Integrados
- `echo` con opción `-n`
- `cd` con ruta relativa o absoluta
- `pwd` sin opciones
- `export` sin opciones
- `unset` sin opciones
- `env` sin opciones ni argumentos
- `exit` sin opciones

#### Características del Shell
- Historial de comandos
- Comillas simples (`'`) y dobles (`"`)
- Redirecciones:
  - `<` redirigir entrada
  - `>` redirigir salida
  - `<<` here_doc
  - `>>` añadir a salida
- Tuberías (`|`)
- Variables de entorno (`$VAR`)
- Estado de salida (`$?`)
- Manejo de señales (Ctrl-C, Ctrl-D, Ctrl-\)

### Compilación

```bash
make        # Compilar el programa
make clean  # Eliminar archivos objeto
make fclean # Eliminar archivos objeto y ejecutable
make re     # Recompilar todo
```

### Uso

```bash
./minishell
# Abre el prompt del shell donde puedes ejecutar comandos
```

### Ejemplos de Comandos

```bash
minishell$ echo "Hola Mundo"
minishell$ ls -la | grep minishell
minishell$ cat < entrada.txt | wc -l > salida.txt
minishell$ export PATH=/usr/bin:/bin
minishell$ cd ..
```
