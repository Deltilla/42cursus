# Push Swap

## 🇬🇧 English Version | [Leer en español 🇪🇸↓](#acerca-de-push_swap)

### About Push Swap

**Push Swap** is a sorting algorithm project where you must sort a stack of integers using a limited set of operations and two stacks (stack A and stack B). The challenge is to sort the data with the minimum number of operations possible.

### Project Objectives

- Develop and implement an efficient sorting algorithm
- Understand algorithm complexity and optimization
- Work with stack data structures
- Master the use of a limited instruction set
- Analyze and improve algorithmic performance

### Available Operations

- `sa` - Swap the first two elements at the top of stack A
- `sb` - Swap the first two elements at the top of stack B
- `ss` - `sa` and `sb` at the same time
- `pa` - Push the first element from B to A
- `pb` - Push the first element from A to B
- `ra` - Rotate stack A (shift all elements up by 1)
- `rb` - Rotate stack B (shift all elements up by 1)
- `rr` - `ra` and `rb` at the same time
- `rra` - Reverse rotate stack A (shift all elements down by 1)
- `rrb` - Reverse rotate stack B (shift all elements down by 1)
- `rrr` - `rra` and `rrb` at the same time

### Performance Goals

- 3 numbers: maximum 3 operations
- 5 numbers: maximum 12 operations
- 100 numbers: less than 700 operations for 5 points, less than 900 for 4 points
- 500 numbers: less than 5500 operations for 5 points, less than 7000 for 4 points

### Compilation

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

### Usage Example

```bash
./push_swap 4 67 3 87 23
# Outputs the sequence of operations to sort the numbers
```

***

## 🇪🇸 Versión en Español | [Read in English 🇬🇧↑](#about-push_swap)

### Acerca de Push Swap

**Push Swap** es un proyecto de algoritmo de ordenamiento donde debes ordenar una pila de enteros usando un conjunto limitado de operaciones y dos pilas (pila A y pila B). El desafío es ordenar los datos con el mínimo número de operaciones posible.

### Objetivos del Proyecto

- Desarrollar e implementar un algoritmo de ordenamiento eficiente
- Comprender la complejidad algorítmica y la optimización
- Trabajar con estructuras de datos tipo pila
- Dominar el uso de un conjunto limitado de instrucciones
- Analizar y mejorar el rendimiento algorítmico

### Operaciones Disponibles

- `sa` - Intercambiar los dos primeros elementos en la cima de la pila A
- `sb` - Intercambiar los dos primeros elementos en la cima de la pila B
- `ss` - `sa` y `sb` al mismo tiempo
- `pa` - Empujar el primer elemento de B a A
- `pb` - Empujar el primer elemento de A a B
- `ra` - Rotar la pila A (desplazar todos los elementos hacia arriba en 1)
- `rb` - Rotar la pila B (desplazar todos los elementos hacia arriba en 1)
- `rr` - `ra` y `rb` al mismo tiempo
- `rra` - Rotar en reversa la pila A (desplazar todos los elementos hacia abajo en 1)
- `rrb` - Rotar en reversa la pila B (desplazar todos los elementos hacia abajo en 1)
- `rrr` - `rra` y `rrb` al mismo tiempo

### Objetivos de Rendimiento

- 3 números: máximo 3 operaciones
- 5 números: máximo 12 operaciones
- 100 números: menos de 700 operaciones para 5 puntos, menos de 900 para 4 puntos
- 500 números: menos de 5500 operaciones para 5 puntos, menos de 7000 para 4 puntos

### Compilación

```bash
make        # Compilar el programa
make clean  # Eliminar archivos objeto
make fclean # Eliminar archivos objeto y ejecutable
make re     # Recompilar todo
```

### Ejemplo de Uso

```bash
./push_swap 4 67 3 87 23
# Muestra la secuencia de operaciones para ordenar los números
```
