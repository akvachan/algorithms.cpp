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

### Search
- BinarySearch

### Sort
- BubbleSort
- InsertionSort
- QuickSort

### Linear structures
- Deque
- DynamicArray
- SinglyLinkedList
- RingBuffer

### Node structures
- BinaryNode
- DoublyNode
- SinglyNode
- TrieNode

### Tree-like structures
- BinaryHeap
- BinarySearchTree
- Trie

### Graphs 
- Graph BFS traversal on AdjacencyMatrix

## Planned
- FibonacciHeap
- AVLTree
- RedBlackTree
