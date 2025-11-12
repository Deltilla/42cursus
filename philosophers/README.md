# Philosophers

## 🇬🇧 English Version | [Leer en español 🇪🇸↓](#acerca-de-philosophers)

### About Philosophers

**Philosophers** is a project based on the famous Dining Philosophers problem, a classic synchronization problem in computer science. The project teaches concurrent programming, thread management, and synchronization mechanisms using mutexes.

### Project Objectives

- Understand and implement multithreading with pthreads
- Learn about race conditions and deadlocks
- Master mutex usage for thread synchronization
- Solve the Dining Philosophers problem without deadlocks
- Handle timing and thread scheduling

### The Problem

Several philosophers sit at a round table with a bowl of spaghetti in the center. There is one fork between each pair of philosophers. A philosopher needs two forks to eat. The philosophers alternate between three states:
- **Eating**: When they have both forks
- **Thinking**: When they don't have any forks
- **Sleeping**: After eating

### Rules

- Philosophers don't speak with each other
- A philosopher must take the fork on their right and left to eat
- When a philosopher has finished eating, they put down both forks and start sleeping
- Once awake, they start thinking
- The simulation stops when a philosopher dies of starvation

### Program Parameters

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers`: Number of philosophers and forks
- `time_to_die`: Time (ms) a philosopher can survive without eating
- `time_to_eat`: Time (ms) it takes for a philosopher to eat
- `time_to_sleep`: Time (ms) a philosopher spends sleeping
- `[number_of_times_each_philosopher_must_eat]`: Optional parameter

### Compilation

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

### Usage Example

```bash
./philo 5 800 200 200
# 5 philosophers, die after 800ms without eating, 
# eat for 200ms, sleep for 200ms
```

***

## 🇪🇸 Versión en Español | [Read in English 🇬🇧↑](#about-philosophers)

### Acerca de Philosophers

**Philosophers** es un proyecto basado en el famoso problema de los Filósofos Comensales, un problema clásico de sincronización en ciencias de la computación. El proyecto enseña programación concurrente, gestión de hilos y mecanismos de sincronización usando mutexes.

### Objetivos del Proyecto

- Comprender e implementar multihilo con pthreads
- Aprender sobre condiciones de carrera y bloqueos mutuos
- Dominar el uso de mutex para sincronización de hilos
- Resolver el problema de los Filósofos Comensales sin bloqueos mutuos
- Manejar temporización y planificación de hilos

### El Problema

Varios filósofos se sientan en una mesa redonda con un plato de espagueti en el centro. Hay un tenedor entre cada par de filósofos. Un filósofo necesita dos tenedores para comer. Los filósofos alternan entre tres estados:
- **Comiendo**: Cuando tienen ambos tenedores
- **Pensando**: Cuando no tienen ningún tenedor
- **Durmiendo**: Después de comer

### Reglas

- Los filósofos no hablan entre sí
- Un filósofo debe tomar el tenedor de su derecha e izquierda para comer
- Cuando un filósofo termina de comer, suelta ambos tenedores y comienza a dormir
- Una vez despierto, comienza a pensar
- La simulación se detiene cuando un filósofo muere de inanición

### Parámetros del Programa

```bash
./philo número_de_filósofos tiempo_para_morir tiempo_para_comer tiempo_para_dormir [número_de_veces_que_cada_filósofo_debe_comer]
```

- `número_de_filósofos`: Número de filósofos y tenedores
- `tiempo_para_morir`: Tiempo (ms) que un filósofo puede sobrevivir sin comer
- `tiempo_para_comer`: Tiempo (ms) que tarda un filósofo en comer
- `tiempo_para_dormir`: Tiempo (ms) que un filósofo pasa durmiendo
- `[número_de_veces_que_cada_filósofo_debe_comer]`: Parámetro opcional

### Compilación

```bash
make        # Compilar el programa
make clean  # Eliminar archivos objeto
make fclean # Eliminar archivos objeto y ejecutable
make re     # Recompilar todo
```

### Ejemplo de Uso

```bash
./philo 5 800 200 200
# 5 filósofos, mueren después de 800ms sin comer,
# comen durante 200ms, duermen durante 200ms
```
