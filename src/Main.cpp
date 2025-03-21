#include "BinaryHeap.hpp"
#include "BinarySearchTree.hpp"
#include "Deque.hpp"
#include "DynamicArray.hpp"
#include "LinkedList.hpp"
#include "QuickSort.hpp"
#include "RingBuffer.hpp"
#include "Trie.cpp"

#include <cstdlib>
#include <iostream>
#include <vector>

int main() {

  // DynamicArray {{{
  std::cout << "\n-------------------------" << std::endl;
  std::cout << "DynamicArray Demo" << std::endl;
  std::cout << "-------------------------\n" << std::endl;

  ak_algos::DynamicArray arr(5); // Initialize with capacity 5
                                 // Push elements
  for (int i = 1; i <= 7; ++i) {
    arr.pushback(i * 10);
    std::cout << "Pushed: " << i * 10 << ", Size: " << arr.getSize()
              << ", Capacity: " << arr.getCapacity() << std::endl;
  }

  // Access elements using operator[]
  std::cout << "Elements in array: ";
  for (const auto &val : arr) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  // Pop elements
  while (arr.getSize() > 0) {
    int val = arr.popback();
    std::cout << "Popped: " << val << ", Size: " << arr.getSize()
              << ", Capacity: " << arr.getCapacity() << std::endl;
  }

  // Attempting to pop from empty array
  try {
    arr.popback();
  } catch (const std::out_of_range &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  // }}}

  // LinkedList {{{
  std::cout << "\n-------------------------" << std::endl;
  std::cout << "LinkedList Demo" << std::endl;
  std::cout << "-------------------------\n" << std::endl;

  ak_algos::LinkedList list;

  list.insertHead(1);
  list.insertTail(2);
  list.insertTail(3);
  list.insertAt(2, 100);

  std::vector<int> values = list.getValues();
  for (int val : values) {
    std::cout << val << " ";
  }
  std::cout << "\nLength: " << list.getLen() << "\n";

  list.removeAt(1);

  values = list.getValues();
  for (int val : values) {
    std::cout << val << " ";
  }
  std::cout << "\nLength: " << list.getLen() << "\n";

  // }}}

  // Deque {{{
  std::cout << "\n-------------------------" << std::endl;
  std::cout << "Deque Demo" << std::endl;
  std::cout << "-------------------------\n" << std::endl;

  ak_algos::Deque myDeque;

  // Push elements to the back
  myDeque.pushBack(10);
  myDeque.pushBack(20);
  myDeque.pushBack(30);

  // Push elements to the front
  myDeque.pushFront(5);
  myDeque.pushFront(2);

  // Access front and back
  std::cout << "Front element: " << myDeque.front() << std::endl; // Outputs 2
  std::cout << "Back element: " << myDeque.back() << std::endl;   // Outputs 30

  // Pop elements from the front
  try {
    int frontVal = myDeque.popFront();
    std::cout << "Popped from front: " << frontVal << std::endl; // Outputs 2
  } catch (const std::out_of_range &e) {
    std::cerr << e.what() << std::endl;
  }

  // Pop elements from the back
  try {
    int backVal = myDeque.popBack();
    std::cout << "Popped from back: " << backVal << std::endl; // Outputs 30
  } catch (const std::out_of_range &e) {
    std::cerr << e.what() << std::endl;
  }

  // Final front and back
  std::cout << "Front element after pops: " << myDeque.front()
            << std::endl; // Outputs 5
  std::cout << "Back element after pops: " << myDeque.back()
            << std::endl; // Outputs 20
                          // }}}

  // RingBuffer {{{
  std::cout << "\n-------------------------" << std::endl;
  std::cout << "RingBuffer Demo" << std::endl;
  std::cout << "-------------------------\n" << std::endl;

  ak_algos::RingBuffer rb(3); // Create a ring buffer with capacity 3

  rb.enque(10);
  rb.enque(20);
  rb.enque(30);

  std::cout << "Size after 3 enqueues: " << rb.getSize()
            << std::endl; // Should print 3

  rb.enque(40); // Overwrites the oldest element (10)

  std::cout << "Dequeued value: " << rb.deque() << std::endl; // Should print 20
  std::cout << "Size after dequeue: " << rb.getSize()
            << std::endl; // Should print 2

  rb.enque(50);
  rb.enque(60); // Overwrites the next oldest element (30)

  while (rb.getSize() > 0) {
    std::cout << "Dequeued value: " << rb.deque() << std::endl;
  }

  // Attempting to dequeue from an empty buffer will throw an exception
  try {
    rb.deque(); // This will throw
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

  //  Binary Search Tree {{{
  std::cout << "\n-------------------------" << std::endl;
  std::cout << "Binary Search Tree Demo" << std::endl;
  std::cout << "-------------------------\n" << std::endl;

  ak_algos::BinarySearchTree bst;

  // Insert elements
  bst.insert(50);
  bst.insert(30);
  bst.insert(70);
  bst.insert(20);
  bst.insert(40);
  bst.insert(60);
  bst.insert(80);

  // Traverse the tree
  std::vector<int> path;
  bst.traverse(path);
  std::cout << "In-order traversal: ";
  for (int val : path)
    std::cout << val << " ";
  std::cout << std::endl;

  // Find elements
  std::cout << "Find 40: " << (bst.find(40) ? "Found" : "Not Found")
            << std::endl;
  std::cout << "Find 25: " << (bst.find(25) ? "Found" : "Not Found")
            << std::endl;

  // Remove elements
  std::cout << "Remove 20" << '\n';
  bst.remove(20); // Remove leaf node
  std::cout << "Remove 30" << '\n';
  bst.remove(30); // Remove node with one child
  std::cout << "Remove 50" << '\n';
  bst.remove(50); // Remove node with two children

  // Traverse the tree again
  path.clear();
  bst.traverse(path);
  std::cout << "In-order traversal after removals: ";
  for (int val : path)
    std::cout << val << " ";
  std::cout << std::endl;

  // -- }}}

  //  Binary Heap {{{

  std::cout << "\n-------------------------" << std::endl;
  std::cout << "Binary Heap Demo" << std::endl;
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
  trie.insert("asterisk"sv);
  trie.insert("aprehended"sv);
  trie.insert("approved"sv);
  trie.insert("apprised"sv);
  trie.insert("germany"sv);
  trie.insert("googledocs"sv);
  trie.insert("germs"sv);
  trie.insert("gorod"sv);
  trie.insert("zarian"sv);

  std::cout << "\nSize of the trie: " << std::endl;
  std::cout << trie.getSize() << std::endl;

  std::cout << "\nSearch for 'game': " << std::endl;
  auto result = trie.search("game"sv);
  if (result.has_value())
    std::cout << result.value() << std::endl;

  std::cout << "\nTraversal: " << std::endl;
  std::vector<ak_algos::TrieWord> results = trie.traverse();
  for (ak_algos::TrieWord &trieWord : results)
    if (trieWord.score.has_value())
      std::cout << trieWord.word << ", " << trieWord.score.value() << std::endl;
    else
      std::cout << trieWord.word << std::endl;
  
  std::cout << "\nCompletions of 'google': " << std::endl;

  auto completions = trie.complete("google"sv);
  for (ak_algos::TrieWord &trieWord : completions)
    if (trieWord.score.has_value())
      std::cout << trieWord.word << ", " << trieWord.score.value() << std::endl;
    else
      std::cout << trieWord.word << std::endl;



  // -- }}}

  return 0;
}
