#include "BinaryHeap.hpp"
#include "BinarySearch.hpp"
#include "BinarySearchTree.hpp"
#include "Deque.hpp"
#include "DynamicArray.hpp"
#include "QuickSort.hpp"
#include "RingBuffer.hpp"
#include "SinglyLinkedList.hpp"
#include "Traversal.hpp"
#include "Trie.hpp"

#include <cstdlib>
#include <iostream>
#include <ostream>
#include <vector>

int main() {

  // DynamicArray {{{

  std::cout << "\n-------------------------" << std::endl;
  std::cout << "DynamicArray Demo" << std::endl;
  std::cout << "-------------------------\n" << std::endl;

  // Initialize with capacity 5
  ak_algos::DynamicArray arr(5);

  for (int i = 1; i <= 7; ++i) {
    arr.append(i * 10);
    std::cout << "Pushed: " << i * 10 << ", Size: " << arr.getLength()
              << ", Capacity: " << arr.getCapacity() << std::endl;
  }

  std::cout << "Elements in array: ";
  for (const auto &val : arr) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  while (arr.getLength() > 0) {
    int val = arr.pop();
    std::cout << "Popped: " << val << ", Size: " << arr.getLength()
              << ", Capacity: " << arr.getCapacity() << std::endl;
  }

  // Attempting to pop from empty array
  try {
    arr.pop();
  } catch (const std::out_of_range &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  // }}}

  // SinglyLinkedList {{{

  std::cout << "\n-------------------------" << std::endl;
  std::cout << "SinglyLinkedList Demo" << std::endl;
  std::cout << "-------------------------\n" << std::endl;

  ak_algos::SinglyLinkedList list;

  list.insertHead(1);
  list.insertTail(2);
  list.insertTail(3);
  list.insertAt(2, 100);

  std::vector<int> values = list.getValues();
  for (int val : values) {
    std::cout << val << " ";
  }
  std::cout << "\nLength: " << list.getLength() << "\n";

  list.removeAt(1);

  values = list.getValues();
  for (int val : values) {
    std::cout << val << " ";
  }
  std::cout << "\nLength: " << list.getLength() << "\n";

  // }}}

  // Deque {{{

  std::cout << "\n-------------------------" << std::endl;
  std::cout << "Deque Demo" << std::endl;
  std::cout << "-------------------------\n" << std::endl;

  ak_algos::Deque myDeque;

  myDeque.pushBack(10);
  myDeque.pushBack(20);
  myDeque.pushBack(30);

  myDeque.pushFront(5);
  myDeque.pushFront(2);

  std::cout << "Front element: " << myDeque.front() << std::endl; // Outputs 2
  std::cout << "Back element: " << myDeque.back() << std::endl;   // Outputs 30

  try {
    int frontVal = myDeque.popFront();
    std::cout << "Popped from front: " << frontVal << std::endl; // Outputs 2
  } catch (const std::out_of_range &e) {
    std::cerr << e.what() << std::endl;
  }

  try {
    int backVal = myDeque.popBack();
    std::cout << "Popped from back: " << backVal << std::endl; // Outputs 30
  } catch (const std::out_of_range &e) {
    std::cerr << e.what() << std::endl;
  }

  std::cout << "Front element after pops: " << myDeque.front()
            << std::endl; // Outputs 5
  std::cout << "Back element after pops: " << myDeque.back()
            << std::endl; // Outputs 20

  // }}}

  // RingBuffer {{{

  std::cout << "\n-------------------------" << std::endl;
  std::cout << "RingBuffer Demo" << std::endl;
  std::cout << "-------------------------\n" << std::endl;

  // Create a ring buffer with capacity 3
  ak_algos::RingBuffer rb(3);

  rb.push(10);
  rb.push(20);
  rb.push(30);

  std::cout << "Length after 3 enqueues: " << rb.getLength() << std::endl;

  rb.push(40);

  std::cout << "Dequeued value: " << rb.pop() << std::endl;
  std::cout << "Length after dequeue: " << rb.getLength() << std::endl;

  rb.push(50);
  rb.push(60);

  while (rb.getLength() > 0) {
    std::cout << "Dequeued value: " << rb.pop() << std::endl;
  }

  // Attempting to dequeue from an empty buffer will throw an exception
  try {
    rb.pop();
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  // }}}

  // QuickSort {{{

  std::cout << "\n-------------------------" << std::endl;
  std::cout << "QuickSort Demo" << std::endl;
  std::cout << "-------------------------\n" << std::endl;

  std::vector<int> arrayToSort = {-1, -1, 1, 2, -5, -10};
  ak_algos::quickSort(arrayToSort);

  for (int &elem : arrayToSort) {
    std::cout << elem << ",";
  }
  std::cout << std::endl;

  // }}}

  //  BinarySearchTree {{{

  std::cout << "\n-------------------------" << std::endl;
  std::cout << "BinarySearchTree Demo" << std::endl;
  std::cout << "-------------------------\n" << std::endl;

  ak_algos::BinarySearchTree bst;

  bst.insert(50);
  bst.insert(30);
  bst.insert(70);
  bst.insert(20);
  bst.insert(40);
  bst.insert(60);
  bst.insert(80);

  std::vector<int> path = bst.traverse();
  std::cout << "In-order traversal: ";
  for (int val : path)
    std::cout << val << " ";
  std::cout << std::endl;

  std::cout << "Find 40: " << (bst.find(40) ? "Found" : "Not Found")
            << std::endl;
  std::cout << "Find 25: " << (bst.find(25) ? "Found" : "Not Found")
            << std::endl;

  std::cout << "Remove 20" << '\n';
  bst.remove(20);
  std::cout << "Remove 30" << '\n';
  bst.remove(30);
  std::cout << "Remove 50" << '\n';
  bst.remove(50);

  // Traverse the tree again
  path.clear();
  path = bst.traverse();
  std::cout << "In-order traversal after removals: ";
  for (int val : path)
    std::cout << val << " ";
  std::cout << std::endl;

  // -- }}}

  //  BinaryHeap {{{

  std::cout << "\n-------------------------" << std::endl;
  std::cout << "BinaryHeap Demo" << std::endl;
  std::cout << "-------------------------\n" << std::endl;

  ak_algos::BinaryHeap minHeap;

  minHeap.insert(10);
  minHeap.insert(5);
  minHeap.insert(20);
  minHeap.insert(1);

  std::cout << "Extracted: " << minHeap.pop().value_or(-1)
            << std::endl; // Should print 1
  std::cout << "Extracted: " << minHeap.pop().value_or(-1)
            << std::endl; // Should print 5
  std::cout << "Extracted: " << minHeap.pop().value_or(-1)
            << std::endl; // Should print 10
  std::cout << "Extracted: " << minHeap.pop().value_or(-1)
            << std::endl; // Should print 20
  std::cout << "Extracted: " << minHeap.pop().value_or(-1)
            << std::endl; // Should print -1 (empty heap)

  // -- }}}

  // Trie {{{

  std::cout << "\n-------------------------" << std::endl;
  std::cout << "Trie Demo" << std::endl;
  std::cout << "-------------------------\n" << std::endl;

  ak_algos::Trie trie;

  using namespace std::literals;

  trie.insert("google"sv, 20);
  trie.insert("go"sv, 30);
  trie.insert("game"sv, 1);
  trie.insert("apple"sv, 6);
  trie.insert("apple"sv, 10);
  trie.insert("asterisk"sv);
  trie.insert("aprehended"sv);
  trie.insert("approved"sv);
  trie.insert("apprised"sv);
  trie.insert("germany"sv);
  trie.insert("googledocs"sv);
  trie.insert("germs"sv);
  trie.insert("gorod"sv);
  trie.insert("zarian"sv);

  std::cout << "Size of the trie: " << trie.getKeysCount() << std::endl;

  std::cout << "Search for 'germany': " << trie.search("germany"sv)
            << std::endl;

  std::cout << "Score for 'apple': ";
  auto result = trie.getScore("apple"sv);
  if (result.has_value())
    std::cout << result.value() << std::endl;
  else
    std::cout << "None" << std::endl;

  std::cout << "\nTraversal: " << std::endl;
  std::vector<ak_algos::TrieWord> results = trie.traverse();
  for (ak_algos::TrieWord &trieWord : results)
    if (trieWord.score.has_value())
      std::cout << trieWord.word << ", " << trieWord.score.value() << std::endl;
    else
      std::cout << trieWord.word << std::endl;

  trie.insert("apprised"sv, 101);
  trie.insert("gorod"sv, 101);

  std::cout << "\nSize of the trie: " << trie.getKeysCount() << std::endl;

  std::cout << "\nCompletions of 'go': " << std::endl;
  auto completions = trie.complete("go"sv);
  for (ak_algos::TrieWord &trieWord : completions)
    if (trieWord.score.has_value())
      std::cout << trieWord.word << ", " << trieWord.score.value() << std::endl;
    else
      std::cout << trieWord.word << std::endl;

  std::cout << "\nRemoving 'germany'" << std::endl;
  trie.remove("germany"sv);

  std::cout << "Removing 'apple'" << std::endl;
  trie.remove("apple"sv);

  std::cout << "Removing 'go'" << std::endl;
  trie.remove("go"sv);

  std::cout << "Removing 'google'" << std::endl;
  trie.remove("google"sv);

  std::cout << "\nTraversal: " << std::endl;
  results.clear();
  results = trie.traverse();
  for (ak_algos::TrieWord &trieWord : results)
    if (trieWord.score.has_value())
      std::cout << trieWord.word << ", " << trieWord.score.value() << std::endl;
    else
      std::cout << trieWord.word << std::endl;

  std::cout << "\nSize of the trie: " << trie.getKeysCount() << std::endl;
  std::cout << "Search for 'germany': " << trie.search("germany"sv)
            << std::endl;
  std::cout << "Search for 'go': " << trie.search("go"sv) << std::endl;

  // -- }}}

  // BinarySearch {{{

  std::cout << "\n-------------------------" << std::endl;
  std::cout << "BinarySearch Demo" << std::endl;
  std::cout << "-------------------------\n" << std::endl;

  std::vector<char> someChars{'a', 'b', 'c', 'd', 'e', 'f'};
  std::vector<int> someInts{1, 2, 3, 4, 5};

  auto charResult = ak_algos::binarySearch<char>(someChars, 'a');
  auto intResult = ak_algos::binarySearch<int>(someInts, 3);

  std::cout << "Search for 'c': ";
  if (charResult.has_value())
    std::cout << charResult.value() << std::endl;

  std::cout << "Search for '3': ";
  if (intResult.has_value())
    std::cout << intResult.value() << std::endl;

  // }}}

  // Graph Traversals {{{

  ak_algos::AdjacencyMatrix graph = {
      {
          0.0f,
          3.0f,
          7.0f,
          2.0f,
          0.0f,
      },
      {
          1.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
      },
      {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          9.0f,
      },
      {
          8.0f,
          0.0f,
          5.0f,
          0.0f,
          4.0f,
      },
      {
          0.0f,
          0.0f,
          0.0f,
          0.0f,
          0.0f,
      },
  };

  std::vector<int> gpath;
  ak_algos::breadthSearch(graph, gpath, 0, 4);

  for (const int &x : gpath) {
    std::cout << x << std::endl;
  }

  // -- }}}

  return 0;
}
