# So Long

## 🇬🇧 English Version | [Leer en español 🇪🇸↓](#acerca-de-so_long)

### About So Long

**So Long** is a small 2D game project where you create a simple game using the MiniLibX graphical library. The player must collect all collectibles on the map and reach the exit with the minimum number of moves possible.

### Project Objectives

- Learn the basics of graphical programming
- Work with the MiniLibX library
- Handle keyboard events and window management
- Parse and validate map files
- Implement game logic and movement
- Display textures and sprites

### Game Rules

- The player can move in 4 directions: up, down, left, right
- The player cannot move through walls
- The player must collect all collectibles before reaching the exit
- The number of movements is displayed in the terminal
- The game ends when the player reaches the exit after collecting all items

### Map Components

- `1` - Wall
- `0` - Empty space
- `C` - Collectible
- `E` - Exit
- `P` - Player starting position

### Map Requirements

- The map must be rectangular
- The map must be surrounded by walls
- The map must contain exactly one exit, at least one collectible, and one starting position
- There must be a valid path from the player to all collectibles and the exit

### Controls

- `W` or `↑` - Move up
- `A` or `←` - Move left
- `S` or `↓` - Move down
- `D` or `→` - Move right
- `ESC` - Close the game

### Compilation

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

### Usage

```bash
./so_long maps/map.ber
```

***

## 🇪🇸 Versión en Español | [Read in English 🇬🇧↑](#about-so_long)

### Acerca de So Long

**So Long** es un proyecto de juego 2D pequeño donde creas un juego simple usando la biblioteca gráfica MiniLibX. El jugador debe recolectar todos los coleccionables en el mapa y alcanzar la salida con el mínimo número de movimientos posible.

### Objetivos del Proyecto

- Aprender los conceptos básicos de programación gráfica
- Trabajar con la biblioteca MiniLibX
- Manejar eventos de teclado y gestión de ventanas
- Analizar y validar archivos de mapa
- Implementar lógica de juego y movimiento
- Mostrar texturas y sprites

### Reglas del Juego

- El jugador puede moverse en 4 direcciones: arriba, abajo, izquierda, derecha
- El jugador no puede moverse a través de paredes
- El jugador debe recolectar todos los coleccionables antes de alcanzar la salida
- El número de movimientos se muestra en la terminal
- El juego termina cuando el jugador alcanza la salida después de recolectar todos los objetos

### Componentes del Mapa

- `1` - Pared
- `0` - Espacio vacío
- `C` - Coleccionable
- `E` - Salida
- `P` - Posición inicial del jugador

### Requisitos del Mapa

- El mapa debe ser rectangular
- El mapa debe estar rodeado de paredes
- El mapa debe contener exactamente una salida, al menos un coleccionable y una posición inicial
- Debe haber un camino válido desde el jugador hasta todos los coleccionables y la salida

### Controles

- `W` o `↑` - Mover arriba
- `A` o `←` - Mover izquierda
- `S` o `↓` - Mover abajo
- `D` o `→` - Mover derecha
- `ESC` - Cerrar el juego

### Compilación

```bash
make        # Compilar el programa
make clean  # Eliminar archivos objeto
make fclean # Eliminar archivos objeto y ejecutable
make re     # Recompilar todo
```

### Uso

```bash
./so_long maps/mapa.ber
```
