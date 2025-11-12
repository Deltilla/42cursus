# CPP Module 08

## Templated Containers, Iterators, and Algorithms

### Topics Covered

This module introduces the Standard Template Library (STL):
- **STL containers**: vector, list, deque, stack, queue
- **Iterators**: Accessing container elements in a generic way
- **Algorithms**: Standard algorithms that work with containers
- **Function objects**: Functors and predicates

### Exercises

- **ex00**: Easy find
- **ex01**: Span
- **ex02**: Mutated abomination

### Key Concepts

- Understanding STL container characteristics
- Iterator categories (input, output, forward, bidirectional, random access)
- Common STL algorithms (find, sort, copy, etc.)
- Creating custom containers that work with STL algorithms
- Exception safety in containers
- Container adapters (stack, queue)

### STL Containers Overview

- **vector**: Dynamic array with random access
- **list**: Doubly-linked list
- **deque**: Double-ended queue
- **stack**: LIFO container adapter
- **queue**: FIFO container adapter
- **map/set**: Associative containers

### Important Notes

- Choose the right container for your needs
- Understand iterator invalidation rules
- Prefer STL algorithms over hand-written loops
- Use const_iterator when not modifying elements

### Compilation

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program_name
```
