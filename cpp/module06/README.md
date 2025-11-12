# CPP Module 06

## C++ Casts

### Topics Covered

This module covers the different types of casting in C++:
- **static_cast**: Compile-time type conversions
- **dynamic_cast**: Runtime type checking and conversion
- **reinterpret_cast**: Low-level reinterpreting of bit patterns
- **const_cast**: Removing const or volatile qualifiers
- **C-style casts**: Why to avoid them in C++

### Exercises

- **ex00**: Conversion of scalar types
- **ex01**: Serialization
- **ex02**: Identify real type

### Key Concepts

- Understanding when to use each cast type
- Runtime Type Information (RTTI)
- The dangers of improper casting
- Type safety in C++
- Serialization and deserialization
- Upcasting and downcasting in class hierarchies

### Important Notes

- `static_cast` is for compile-time conversions
- `dynamic_cast` requires RTTI and works with polymorphic types
- `reinterpret_cast` is dangerous and should be used sparingly
- `const_cast` should only be used when absolutely necessary
- Prefer C++ casts over C-style casts for type safety

### Compilation

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program_name
```
