#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "SinglyNode.hpp"
#include <vector>

// LinkedList class

namespace ak_algos {

class SinglyLinkedList {
public:
  SinglyLinkedList();  // Constructor
  ~SinglyLinkedList(); // Destructor

  int get(int index) const; // Get value by index
  int getLength() const;       // Get length of the list

  void insertAt(int index, int val); // Insert at arbitrary index 
  void insertHead(int val); // Insert at the head
  void insertTail(int val); // Insert at the tail

  bool removeAt(int index); // Remove node by index

  std::vector<int> getValues() const; // Get all values as a vector

private:
  int _len;         // Length of the list
  SinglyNode *_startNode; // Pointer to the first node
  SinglyNode *_endNode;   // Pointer to the last node
};

} // namespace ak_algos

#endif // LINKEDLIST_H
