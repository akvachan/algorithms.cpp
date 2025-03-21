#ifndef BINARYNODE_H
#define BINARYNODE_H

namespace ak_algos {

// Binary Node structure
struct BinaryNode {

  // Constructor
  BinaryNode(int val) : left(nullptr), right(nullptr), val(val) {}
  BinaryNode() : left(nullptr), right(nullptr), val(0) {}

  BinaryNode *left;
  BinaryNode *right;
  int val;
};

} // namespace ak_algos

#endif // BINARYNODE_H
