#ifndef DOUBLYNODE_H
#define DOUBLYNODE_H

// Node structure
namespace ak_algos {

struct DoublyNode {
  DoublyNode *prev;
  DoublyNode *next;
  int val;

  // Constructor
  DoublyNode(DoublyNode *prev = nullptr, DoublyNode *next = nullptr,
             int val = 0)
      : prev(prev), next(next), val(val) {}
};

} // namespace ak_algos

#endif // DOUBLYNODE_H
