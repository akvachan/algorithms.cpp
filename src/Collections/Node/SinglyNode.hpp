#ifndef SINGLYNODE_H
#define SINGLYNODE_H

// Node structure
namespace ak_algos {

struct SinglyNode {
  SinglyNode *next;
  int val;

  // Constructor
  SinglyNode(SinglyNode *nextNode = nullptr, int value = 0)
      : next(nextNode), val(value) {}
};

} // namespace ak_algos

#endif // SINGLYNODE_H
