#ifndef BINARYNODE_H
#define BINARYNODE_H

namespace ak_algos {

struct BinaryNode {
  BinaryNode(int val);
  BinaryNode();

  BinaryNode *left;
  BinaryNode *right;
  int val;
};

} // namespace ak_algos

#endif // BINARYNODE_H
