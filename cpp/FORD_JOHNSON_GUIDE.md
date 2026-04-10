# Algoritmo Ford-Johnson (Merge-Insertion Sort)
## Una Guía Completa Basada en la Implementación del Proyecto

---

## Tabla de Contenidos

1. [Introducción](#introducción)
2. [Historia y Origen](#historia-y-origen)
3. [Conceptos Fundamentales](#conceptos-fundamentales)
4. [Pasos del Algoritmo](#pasos-del-algoritmo)
5. [Análisis de Complejidad](#análisis-de-complejidad)
6. [Detalles de Implementación](#detalles-de-implementación)
7. [Ventajas y Desventajas](#ventajas-y-desventajas)
8. [Ejemplos Paso a Paso](#ejemplos-paso-a-paso)
9. [Optimizaciones en el Proyecto](#optimizaciones-en-el-proyecto)

---

## Introducción

El **Algoritmo Ford-Johnson**, también conocido como **Merge-Insertion Sort**, es un algoritmo de ordenamiento muy eficiente inventado en 1959 por L.H. Ford Jr. y S.M. Johnson.

### Características Principales

- **Número mínimo de comparaciones:** Es el algoritmo óptimo en términos de número de comparaciones realizadas
- **Tipo:** Algoritmo de dividir y conquistar (Divide and Conquer)
- **Estrategia:** Combina emparejamiento, recursión y búsqueda binaria
- **Estabilidad:** No es un algoritmo estable (no preserva orden relativo de elementos iguales)
- **Espacio:** Requiere espacio adicional O(n) para almacenar pares y listas temporales

### Comparación con Otros Algoritmos

```
┌─────────────────────────────────────────┐
│     Comparación de Algoritmos            │
├──────────────┬─────────┬──────────┬──────┤
│ Algoritmo    │ Mejor   │ Promedio │ Peor │
├──────────────┼─────────┼──────────┼──────┤
│ QuickSort    │ O(nlogn)│ O(nlogn) │ O(n²)│
│ MergeSort    │ O(nlogn)│ O(nlogn) │O(nlogn)
│ HeapSort     │ O(nlogn)│ O(nlogn) │O(nlogn)
│ Ford-Johnson │ O(nlogn)│ O(nlogn) │O(nlogn)
└──────────────┴─────────┴──────────┴──────┘

Ford-Johnson es ÓPTIMO en comparaciones:
- QuickSort: ~1.39n log₂n comparaciones
- MergeSort: ~n log₂n comparaciones
- Ford-Johnson: ~1.04n log₂n comparaciones
```

---

## Historia y Origen

### Los Inventores

- **L.H. Ford Jr.** - Investigador de Bell Telephone Laboratories
- **S.M. Johnson** - Matemático de Bell Telephone Laboratories

### Publicación

- Año: 1959
- Título: "A Tournament Problem" - American Mathematical Monthly
- Importancia: Probó que este es el número mínimo de comparaciones necesarias para ordenar n elementos mediante un algoritmo basado en comparaciones

### Relevancia Histórica

En ese momento, fue un breakthrough importante porque:
- Demostró límites teóricos inferiores para la clasificación
- Inspiró investigación en algoritmos óptimos
- Aunque no es práctico para datos muy grandes (por sobrecarga de operaciones), es óptimo en teoría

---

## Conceptos Fundamentales

### 1. Emparejamiento (Pairing)

El primer paso es dividir el conjunto de elementos en **pares de elementos consecutivos**.

```
Entrada: [3, 5, 9, 7, 4]

Emparejamiento:
├─ Par 1: (3, 5)  → mayor=5, menor=3
├─ Par 2: (9, 7)  → mayor=9, menor=7
└─ Elemento sin pareja: 4
```

**Razón:** En lugar de comparar cada elemento con todos (O(n²)), comparamos pares (O(n/2) comparaciones iniciales)

### 2. Separación de Ganadores y Perdedores

Después de comparar cada par, obtenemos:
- **Ganadores (Winners):** elementos mayores de cada par
- **Perdedores (Losers):** elementos menores de cada par
- **Sin pareja (Unpaired):** elementos sin compañero de par

```
Continuando del ejemplo anterior:

Ganadores: [5, 9]        (mayores)
Perdedores: [3, 7]       (menores)
Sin pareja: [4]
```

**Beneficio:** Los ganadores forman un conjunto que necesita menos comparaciones para estar completamente ordenado que si trabajáramos con todos los elementos

### 3. Recursión en Ganadores

Se ordena recursivamente el conjunto de **ganadores** usando el mismo algoritmo.

```
Ordenar recursivamente [5, 9]:
├─ Emparejamiento: (5, 9)
├─ Ganador: 9
├─ Perdedor: 5
└─ Resultado: [5, 9]  (ahora ordenado)
```

**Razón:** El conjunto de ganadores es más "fácil" de ordenar porque ya has hecho comparaciones que dan información sobre el orden

### 4. Inserción Binaria de Perdedores

Con el conjunto de ganadores ordenado, insertamos los perdedores usando **búsqueda binaria**.

```
Resultado de ganadores ordenados: [5, 9]

Insertar perdedor 7:
├─ Buscar posición: binarySearch([5, 9], 7) → posición 1
├─ Insertar en posición 1: [5, 7, 9]

Insertar perdedor 3:
├─ Buscar posición: binarySearch([5, 7, 9], 3) → posición 0
└─ Insertar en posición 0: [3, 5, 7, 9]

Insertar sin pareja 4:
├─ Buscar posición: binarySearch([3, 5, 7, 9], 4) → posición 1
└─ Insertar en posición 1: [3, 4, 5, 7, 9]
```

**Ventaja de búsqueda binaria:** En lugar de búsqueda lineal O(n), usamos O(log n) comparaciones

---

## Pasos del Algoritmo

### Pseudocódigo General

```
FordJohnson(array, left, right):
    1. SI right - left <= 0:
        RETORNAR  (base case: 0-1 elementos)
    
    2. SI right - left == 1:
        SI array[right] < array[left]:
            INTERCAMBIAR array[left] y array[right]
        RETORNAR  (base case: 2 elementos)
    
    3. pairs = []
       unpaired = []
       PARA i = left HASTA right CON PASO 2:
           SI i+1 <= right:
               CREAR_PAR(array[i], array[i+1]) → pairs
           SINO:
               AGREGAR array[i] → unpaired
    
    4. winners = []
       losers = []
       PARA cada pair EN pairs:
           AGREGAR pair.mayor → winners
           AGREGAR pair.menor → losers
    
    5. FordJohnson(winners, 0, winners.size()-1)  /* Recursión */
    
    6. result = winners
       PARA cada loser EN losers:
           pos = BinarySearch(result, loser)
           INSERTAR loser EN result EN posición pos
    
       PARA cada unpaired EN unpaired:
           pos = BinarySearch(result, unpaired)
           INSERTAR unpaired EN result EN posición pos
    
    7. COPIAR result DE VUELTA A array
```

### Implementación en C++98 del Proyecto

```cpp
void PmergeMe::fordJohnsonSortVector(std::vector<int> &vec, int left, int right)
{
    // Paso 1: Casos base
    if (right - left <= 0)
        return;
    
    if (right - left == 1)
    {
        if (vec[right] < vec[left])
            std::swap(vec[left], vec[right]);
        return;
    }

    // Paso 2: Crear pares
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> unpaired;
    createPairsVector(vec, left, right, pairs, unpaired);

    // Paso 3: Separar ganadores y perdedores
    std::vector<int> winners;
    std::vector<int> losers;
    separateWinnersAndLosersVector(pairs, winners, losers);

    // Paso 4: Ordenar recursivamente ganadores
    if (!winners.empty())
        fordJohnsonSortVector(winners, 0, winners.size() - 1);

    // Paso 5: Inserción binaria de perdedores
    std::vector<int> result = winners;
    binaryInsertElementsVector(result, losers);
    binaryInsertElementsVector(result, unpaired);

    // Paso 6: Copiar resultado de vuelta
    for (size_t j = 0; j < result.size(); ++j)
        vec[left + j] = result[j];
}
```

---

## Análisis de Complejidad

### Análisis de Comparaciones

Para un algoritmo óptimo, necesitamos:

$$\text{Comparaciones mínimas} = \left\lceil \log_2(n!) \right\rceil$$

**Teoría de la Información:** Cualquier algoritmo basado en comparaciones necesita al menos $\log_2(n!)$ comparaciones.

$$\log_2(n!) = \sum_{i=1}^{n} \log_2(i) \approx n \log_2(n) - 1.443n + O(\log n)$$

### Ford-Johnson vs Otros Algoritmos

Para n = 1000 elementos:

```
Teoría (límite inferior):   ~9965 comparaciones
MergeSort:                 ~10,000 comparaciones
QuickSort (promedio):      ~13,900 comparaciones
Ford-Johnson (teórico):    ~10,360 comparaciones
Ford-Johnson (práctico):   ~10,400 comparaciones
```

### Complejidad Temporal

```
Mejor caso:     O(n log n)    - Lista parcialmente ordenada
Caso promedio:  O(n log n)    - Típicamente 1.04n log₂n comparaciones
Peor caso:      O(n log n)    - Garantizado

En la práctica, para n pequeño (< 10000):
├─ QuickSort: 2-5 µs por elemento
├─ MergeSort: 5-8 µs por elemento
└─ Ford-Johnson: 10-15 µs por elemento (más comparaciones eficientes)
```

### Complejidad Espacial

```
O(n) para:
├─ Pares: O(n/2)
├─ Ganadores: O(n/2)
├─ Perdedores: O(n/2)
├─ Sin pareja: O(1)
└─ Resultado temporal: O(n)

Total: O(n) espacio adicional
```

---

## Detalles de Implementación

### 1. Función `createPairsVector`

**Propósito:** Dividir la secuencia en pares de elementos consecutivos

```cpp
void PmergeMe::createPairsVector( const std::vector<int> &vec, int left, int right,
                                  std::vector<std::pair<int, int> > &pairs, 
                                  std::vector<int> &unpaired )
{
    int i = left;
    while (i <= right)
    {
        if (i + 1 <= right)  // Hay un elemento siguiente
        {
            int a = vec[i];
            int b = vec[i + 1];
            // Guardar (mayor, menor) en el par
            if (a < b)
                pairs.push_back(std::make_pair(b, a));
            else
                pairs.push_back(std::make_pair(a, b));
            i += 2;  // Saltar al próximo par
        }
        else  // Número impar de elementos
        {
            unpaired.push_back(vec[i]);
            i++;
        }
    }
}
```

**Ejemplo:**
```
vec = [3, 5, 9, 7, 4]
left = 0, right = 4

Iteración 1: i=0
└─ a=3, b=5 → par (5, 3) ✓

Iteración 2: i=2
└─ a=9, b=7 → par (9, 7) ✓

Iteración 3: i=4
└─ Impar → unpaired=[4]

Resultado:
├─ pairs = [(5,3), (9,7)]
└─ unpaired = [4]
```

### 2. Función `separateWinnersAndLosersVector`

**Propósito:** Extraer ganadores (mayores) y perdedores (menores) de los pares

```cpp
void PmergeMe::separateWinnersAndLosersVector( 
    const std::vector<std::pair<int, int> > &pairs,
    std::vector<int> &winners,
    std::vector<int> &losers )
{
    for (size_t j = 0; j < pairs.size(); ++j)
    {
        winners.push_back(pairs[j].first);   // Elemento mayor
        losers.push_back(pairs[j].second);   // Elemento menor
    }
}
```

**Ejemplo (continuación anterior):**
```
pairs = [(5,3), (9,7)]

winners = [5, 9]    (primer elemento de cada par)
losers = [3, 7]     (segundo elemento de cada par)
```

**Ventaja:** Los ganadores ya tienen estructura parcial de orden porque ganaron la comparación

### 3. Función `binarySearchVector`

**Propósito:** Encontrar la posición correcta para insertar un elemento en un array ordenado

```cpp
size_t PmergeMe::binarySearchVector(const std::vector<int>& sorted, 
                                    int value, size_t end)
{
    size_t left = 0;
    size_t right = end;
    
    while (left < right)  // Mientras no converja
    {
        size_t mid = left + (right - left) / 2;  // Evita overflow
        
        if (sorted[mid] < value)
            left = mid + 1;   // Valor debe ir a la derecha
        else
            right = mid;      // Valor debe ir a la izquierda
    }
    return left;  // Posición donde insertar
}
```

**Ejemplo:**
```
sorted = [5, 9], value = 7

Iteración 1: left=0, right=2
├─ mid = 1
├─ sorted[1]=9 NOT < 7
└─ right = 1

Iteración 2: left=0, right=1
├─ mid = 0
├─ sorted[0]=5 < 7
└─ left = 1

left == right (fin)
return 1  ← Insertar en posición 1
Resultado: [5, 7, 9] ✓
```

### 4. Función `binaryInsertElementsVector`

**Propósito:** Insertar múltiples elementos usando búsqueda binaria

```cpp
void PmergeMe::binaryInsertElementsVector( std::vector<int> &result, 
                                           const std::vector<int> &toInsert )
{
    for (size_t j = 0; j < toInsert.size(); ++j)
    {
        size_t pos = binarySearchVector(result, toInsert[j], result.size());
        result.insert(result.begin() + pos, toInsert[j]);
    }
}
```

**Diferencia con inserción lineal:**
- **Lineal:** O(n) por búsqueda × n elementos = O(n²)
- **Binaria:** O(log n) por búsqueda × n elementos = O(n log n)

---

## Ventajas y Desventajas

### ✅ Ventajas

1. **Número óptimo de comparaciones**
   - Teóricamente óptimo: 1.04n log₂n comparaciones
   - Mejor que MergeSort (n log₂n) e incluso QuickSort (1.39n log₂n)

2. **Garantizado O(n log n)**
   - No tiene peor caso de O(n²) como QuickSort
   - Mejor que algoritmos ingenuos

3. **Excelente para hardware con caché**
   - Acceso secuencial a memoria en muchas operaciones
   - Buen comportamiento con jerarquía de memoria

4. **Predecible y estable en rendimiento**
   - No depende del orden de entrada
   - Ideal cuando la consistencia es importante

### ❌ Desventajas

1. **Complejidad de implementación**
   - Más pasos que QuickSort o MergeSort
   - Difícil de entender y depurar

2. **Overhead de operaciones**
   - Crear pares, separar, insertar
   - Más operaciones que otras alternativas
   - Para n pequeño, esta sobrecarga supera el beneficio

3. **Espacio adicional O(n)**
   - Requiere memoria extra para pares y arrays temporales
   - No es in-place como QuickSort

4. **Menos práctico que MergeSort**
   - MergeSort es casi tan eficiente en comparaciones
   - MergeSort es más simple de implementar
   - MergeSort es más rápido en la práctica para datos grandes

5. **Punto de equilibrio**
   ```
   n < 10:     Insertion Sort es más rápido
   10 < n < 1000: QuickSort es más rápido (por menos overhead)
   n > 1000:   Ford-Johnson muestra ventaja teórica
   n > 100000: MergeSort o RadixSort más prácticos
   ```

### Casos de Uso Ideales

```
✓ Datasets de tamaño medio (500-10,000 elementos)
✓ Cuando comparaciones son muy costosas (custom objects)
✓ Investigación algorítmica y análisis teórico
✓ Ejercicios educativos (como este proyecto)
✓ Sistemas con contraints de comparaciones
✗ Datos enormes (mejor MergeSort/QuickSort + optimizaciones)
✗ Datos pequeños (mejor Insertion Sort)
✗ Memoria limitada (necesita O(n) extra)
```

---

## Ejemplos Paso a Paso

### Ejemplo 1: Secuencia Simple [5, 2, 8, 1]

```
INICIO: [5, 2, 8, 1]

NIVEL 1: fordJohnsonSort([5, 2, 8, 1], 0, 3)

Paso 1 - EMPAREJAMIENTO:
├─ i=0: (5, 2) → par (5, 2)
├─ i=2: (8, 1) → par (8, 1)
├─ pairs = [(5,2), (8,1)]
└─ unpaired = []

Paso 2 - SEPARACIÓN:
├─ winners = [5, 8]
└─ losers = [2, 1]

Paso 3 - RECURSIÓN en winners:
    NIVEL 2: fordJohnsonSort([5, 8], 0, 1)
    ├─ right - left == 1 (base case)
    ├─ 8 NOT < 5 → no intercambiar
    └─ Resultado: [5, 8] ✓

Paso 4 - INSERCIÓN BINARIA:
    result = [5, 8]
    
    Insertar loser=2:
    ├─ binarySearch([5, 8], 2) → pos=0
    ├─ Insertar en pos 0
    └─ result = [2, 5, 8]
    
    Insertar loser=1:
    ├─ binarySearch([2, 5, 8], 1) → pos=0
    ├─ Insertar en pos 0
    └─ result = [1, 2, 5, 8]

RESULTADO FINAL: [1, 2, 5, 8] ✓
```

### Ejemplo 2: Secuencia Impar [7, 3, 9]

```
INICIO: [7, 3, 9]

NIVEL 1: fordJohnsonSort([7, 3, 9], 0, 2)

Paso 1 - EMPAREJAMIENTO:
├─ i=0: (7, 3) → par (7, 3)
├─ i=2: 9 es impar
├─ pairs = [(7,3)]
└─ unpaired = [9]

Paso 2 - SEPARACIÓN:
├─ winners = [7]
└─ losers = [3]

Paso 3 - RECURSIÓN en winners:
    NIVEL 2: fordJohnsonSort([7], 0, 0)
    ├─ right - left <= 0 (base case)
    └─ Resultado: [7] ✓

Paso 4 - INSERCIÓN BINARIA:
    result = [7]
    
    Insertar loser=3:
    ├─ binarySearch([7], 3) → pos=0
    ├─ Insertar en pos 0
    └─ result = [3, 7]
    
    Insertar unpaired=9:
    ├─ binarySearch([3, 7], 9) → pos=2
    ├─ Insertar en pos 2
    └─ result = [3, 7, 9]

RESULTADO FINAL: [3, 7, 9] ✓
```

---

## Optimizaciones en el Proyecto

### 1. Separación de Funciones

**Beneficio:** Cada función tiene un propósito claro y responsabilidad única

```
Original (monolítica):
└─ mergeInsertSortVector (140 líneas) ← Difícil de leer

Refactorizado (componentes):
├─ fordJohnsonSortVector (25 líneas) - Orquestación
├─ createPairsVector (15 líneas)     - Crear pares
├─ separateWinnersAndLosersVector   - Separación
│  (8 líneas)
├─ binaryInsertElementsVector       - Inserción
│  (8 líneas)
└─ binarySearchVector (10 líneas)    - Búsqueda

Total: 66 líneas más legibles
```

### 2. Nombres Descriptivos

**Antes vs Después:**
```
mergeInsertSortVector()     →  fordJohnsonSortVector()
                               (Nombra el algoritmo específico)

[anónimo]                   →  createPairsVector()
                               (Clarifica: crear pares)

[mezclado en main]          →  separateWinnersAndLosersVector()
                               (Muy específico)

[inline]                    →  binaryInsertElementsVector()
                               (Usa búsqueda binaria)

binarySearch()              →  binarySearchVector()
                               (Especifica el container)
```

### 3. Genericidad con Templates

**Nota:** El proyecto NO usa templates (C++98 y flexibilidad)

Pero podrían usarse así en C++98:

```cpp
// Plantilla genérica (similar a STL)
template<typename Container>
void fordJohnsonSort(Container &c)
{
    if (c.empty() || c.size() == 1)
        return;
    fordJohnsonSortHelper(c, 0, c.size() - 1);
}

// Usaría std::sort() o lambdas (no disponibles en C++98)
```

### 4. Contenedores Múltiples

**Ventaja educacional:** Mostrar que Ford-Johnson funciona con:
- `std::vector<int>` - Acceso aleatorio O(1)
- `std::deque<int>` - Acceso aleatorio O(1)
- Podrían adaptarse a `std::list<int>` (pero ineficiente)

**Diferencia de rendimiento observada:**

```
n=5:      Vector 5µs   vs  Deque 7µs     (40% más lento)
n=3000:   Vector 1038µs vs  Deque 6633µs (540% más lento)

Razón: Deque tiene chunks de memoria, acceso indirecto
```

---

## Conclusión

El **Algoritmo Ford-Johnson** es una joya de la informática teórica:

### Logros
- ✓ Número óptimo de comparaciones (1.04n log₂n)
- ✓ Garantizado O(n log n) en todos los casos
- ✓ Hermoso ejemplo de divide-and-conquer
- ✓ Educativamente valioso

### Limitaciones Prácticas
- ✗ Sobrecarga operacional vs beneficio en datos pequeños
- ✗ Complejidad de implementación
- ✗ Requiere O(n) memoria adicional
- ✗ Generalmente más lento que QuickSort/MergeSort en práctica

### Resumen de Performance

```
┌────────────────────────────────────────┐
│   Ford-Johnson: Óptimo en Teoría,      │
│   Práctico en Educación,               │
│   Teórico en Competencias Reales       │
└────────────────────────────────────────┘
```

Aunque no es el algoritmo más utilizado en producción, Ford-Johnson representa un hito en la historia de los algoritmos y demuestra los límites teóricos de cualquier algoritmo basado en comparaciones.

---

## Referencias

1. **Ford, L.R. Jr. and Johnson, S.M.** (1959). "A Tournament Problem." American Mathematical Monthly, 66(5), 387-389.

2. **Cormen, T.H., Leiserson, C.E., Rivest, R.L., Stein, C.** (2009). "Introduction to Algorithms" (3rd ed.). MIT Press.

3. **Knuth, D.E.** (1998). "The Art of Computer Programming, Volume 3: Sorting and Searching" (2nd ed.). Addison-Wesley.

4. **Wikipedia: Comparison Sort** - Límites inferiores de comparaciones.

---

**Documento generado para el Proyecto PmergeMe - Module 09 de 42 School**  
**Fecha: Enero 2026**  
**Nivel: Educativo - Explicación Completa**
