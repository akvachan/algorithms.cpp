# algorithms.cpp

Implementing algorithms and data structure in C++.

## Setup

You need CMake (sorry for that).

Just do:
```
git clone --depth=1 https://github.com/akvachan/algorithms.cpp.git
cd algorithms.cpp
cmake -B build
cmake --build build --parallel 10
build/Algorithms
```

## Currently implemented

### Sort
- BubbleSort
- InsertionSort
- QuickSort

### Linear structures
- Deque
- DynamicArray
- LinkedList
- RingBuffer

### Node structures
- BinaryNode
- DoublyGraphNode
- DoublyNode
- GraphNode
- SinglyNode
- TrieNode

### Tree-like structures
- BinaryHeap
- BinarySearchTree
- Trie


## Planned

### Implementations
- Graphs
- FibonacciHeap
- AVLTree
- RedBlackTree
- BinarySearch
- LinearSearch

### Features
- Single header file for everything
- Make build for MacOS and Linux
