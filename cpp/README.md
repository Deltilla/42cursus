# CPP Modules (C++)

## 🇬🇧 English Version | [Leer en español 🇪🇸↓](#acerca-de-cpp-modules)

### About CPP Modules

The **CPP Modules** are a series of 10 modules (00-09) that introduce Object-Oriented Programming concepts using C++. These modules cover everything from basic C++ syntax to advanced topics like templates, STL containers, and iterators.

### Module Overview

| Module | Topic | Description |
| :--- | :--- | :--- |
| [Module 00](./module00/README.md) | Introduction to C++ | Namespaces, classes, member functions, stdio streams, initialization lists, static, const |
| [Module 01](./module01/README.md) | Memory & Pointers | Memory allocation, pointers to members, references, switch statement |
| [Module 02](./module02/README.md) | Ad-hoc Polymorphism | Operator overloading, orthodox canonical class form, fixed-point numbers |
| [Module 03](./module03/README.md) | Inheritance | Inheritance basics, virtual functions, multiple inheritance |
| [Module 04](./module04/README.md) | Subtype Polymorphism | Abstract classes, interfaces, deep copy vs shallow copy |
| [Module 05](./module05/README.md) | Exceptions | Try/catch blocks, exception handling, bureaucrat class |
| [Module 06](./module06/README.md) | C++ Casts | Static cast, dynamic cast, reinterpret cast, const cast |
| [Module 07](./module07/README.md) | Templates | Function templates, class templates |
| [Module 08](./module08/README.md) | Templated Containers | STL containers, iterators, algorithms |
| [Module 09](./module09/README.md) | Advanced STL | Advanced containers, reverse Polish notation, merge-insert sort |

### Learning Objectives

Throughout these modules, you will learn:
- Object-Oriented Programming principles
- C++ syntax and semantics
- Memory management in C++
- Inheritance and polymorphism
- Exception handling
- Type casting in C++
- Template programming
- Standard Template Library (STL)
- Modern C++ best practices

### Compilation

Each exercise within the modules typically uses C++98 standard and can be compiled with:

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program_name
```

Or using the provided Makefile in each exercise directory:

```bash
make
```

### Important Notes

- All modules must be compiled with `-Wall -Wextra -Werror` flags
- Standard is C++98 unless otherwise specified
- Memory leaks are strictly forbidden
- Each class must follow the Orthodox Canonical Form when appropriate
- No external libraries (except STL where permitted)

***

## 🇪🇸 Versión en Español | [Read in English 🇬🇧↑](#about-cpp-modules)

### Acerca de CPP Modules

Los **Módulos CPP** son una serie de 10 módulos (00-09) que introducen conceptos de Programación Orientada a Objetos usando C++. Estos módulos cubren desde la sintaxis básica de C++ hasta temas avanzados como plantillas, contenedores STL e iteradores.

### Resumen de Módulos

| Módulo | Tema | Descripción |
| :--- | :--- | :--- |
| [Módulo 00](./module00/README.md) | Introducción a C++ | Espacios de nombres, clases, funciones miembro, streams stdio, listas de inicialización, static, const |
| [Módulo 01](./module01/README.md) | Memoria y Punteros | Asignación de memoria, punteros a miembros, referencias, declaración switch |
| [Módulo 02](./module02/README.md) | Polimorfismo Ad-hoc | Sobrecarga de operadores, forma canónica ortodoxa de clases, números de punto fijo |
| [Módulo 03](./module03/README.md) | Herencia | Conceptos básicos de herencia, funciones virtuales, herencia múltiple |
| [Módulo 04](./module04/README.md) | Polimorfismo de Subtipos | Clases abstractas, interfaces, copia profunda vs copia superficial |
| [Módulo 05](./module05/README.md) | Excepciones | Bloques try/catch, manejo de excepciones, clase burócrata |
| [Módulo 06](./module06/README.md) | Conversiones C++ | Static cast, dynamic cast, reinterpret cast, const cast |
| [Módulo 07](./module07/README.md) | Plantillas | Plantillas de funciones, plantillas de clases |
| [Módulo 08](./module08/README.md) | Contenedores Templados | Contenedores STL, iteradores, algoritmos |
| [Módulo 09](./module09/README.md) | STL Avanzada | Contenedores avanzados, notación polaca inversa, ordenamiento merge-insert |

### Objetivos de Aprendizaje

A lo largo de estos módulos, aprenderás:
- Principios de Programación Orientada a Objetos
- Sintaxis y semántica de C++
- Gestión de memoria en C++
- Herencia y polimorfismo
- Manejo de excepciones
- Conversión de tipos en C++
- Programación con plantillas
- Biblioteca de Plantillas Estándar (STL)
- Mejores prácticas de C++ moderno

### Compilación

Cada ejercicio dentro de los módulos típicamente usa el estándar C++98 y puede compilarse con:

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o nombre_programa
```

O usando el Makefile proporcionado en cada directorio de ejercicio:

```bash
make
```

### Notas Importantes

- Todos los módulos deben compilarse con las flags `-Wall -Wextra -Werror`
- El estándar es C++98 a menos que se especifique lo contrario
- Las fugas de memoria están estrictamente prohibidas
- Cada clase debe seguir la Forma Canónica Ortodoxa cuando sea apropiado
- No se permiten bibliotecas externas (excepto STL donde se permite)
