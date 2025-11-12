# CPP Module 07

## C++ Templates

### Topics Covered

This module introduces template programming in C++:
- **Function templates**: Generic functions that work with any type
- **Class templates**: Generic classes parameterized by types
- **Template instantiation**: How templates are compiled
- **Template specialization**: Customizing templates for specific types

### Exercises

- **ex00**: Start with a few functions
- **ex01**: Iter
- **ex02**: Array

### Key Concepts

- Understanding generic programming
- Writing type-independent code
- Template syntax and usage
- Implicit vs explicit template instantiation
- Template type deduction
- Common template patterns

### Benefits of Templates

- Code reusability
- Type safety
- Performance (no runtime overhead)
- Compile-time polymorphism
- Foundation for STL

### Important Notes

- Templates are compiled when instantiated, not when defined
- Template code typically goes in header files
- Compilation errors can be verbose and hard to read
- Templates are resolved at compile time, not runtime

### Compilation

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program_name
```
