#include "SinglyLinkedList.hpp"
#include "SinglyNode.hpp"

namespace ak_algos {

// Constructor
SinglyLinkedList::SinglyLinkedList() : _len(0), _startNode(nullptr), _endNode(nullptr) {}

// Destructor
SinglyLinkedList::~SinglyLinkedList() {
  while (_startNode) {
    SinglyNode *temp = _startNode;
    _startNode = _startNode->next;
    delete temp;
  }
}

// Get value by index
int SinglyLinkedList::get(int index) const {
  if (index < 0 || index >= _len)
    return -1;

  SinglyNode *currNode = _startNode;
  for (int i = 0; i < index; i++) {
    currNode = currNode->next;
  }

  return currNode ? currNode->val : -1;
}

// Get length of the list
int SinglyLinkedList::getLength() const { return _len; }

// Insert at the head
void SinglyLinkedList::insertHead(int val) {
  SinglyNode *newHead = new SinglyNode(_startNode, val);
  if (_len == 0) {
    _endNode = newHead;
  }
  _startNode = newHead;
  _len++;
}

// Insert at the tail
void SinglyLinkedList::insertTail(int val) {
  SinglyNode *newTail = new SinglyNode(nullptr, val);
  if (_len == 0) {
    _startNode = newTail;
  } else {
    _endNode->next = newTail;
  }
  _endNode = newTail;
  _len++;
}

void SinglyLinkedList::insertAt(int index, int val) {
  if (index == 0)
    insertHead(val);
  else if (index == _len)
    insertTail(val);
  else if (index < _len && index > 0) {
    SinglyNode *newNode = new SinglyNode(nullptr, val);

    SinglyNode *currentNode = _startNode;
    for (int i = 0; i < index - 1; i++)
      currentNode = currentNode->next;

    SinglyNode *temp = currentNode->next;
    currentNode->next = newNode;
    newNode->next = temp;

    _len++;
  }
}

// Remove node by index
bool SinglyLinkedList::removeAt(int index) {
  if (index < 0 || index >= _len)
    return false;

  if (index == 0) {
    SinglyNode *temp = _startNode;
    _startNode = _startNode->next;
    delete temp;

    if (--_len == 0) {
      _endNode = nullptr;
    }
    return true;
  }

  SinglyNode *prevNode = _startNode;
  for (int i = 0; i < index - 1; i++) {
    prevNode = prevNode->next;
  }

  SinglyNode *targetNode = prevNode->next;
  prevNode->next = targetNode->next;

  if (index == _len - 1) {
    _endNode = prevNode;
  }

  delete targetNode;
  _len--;
  return true;
}

// Get all values as a vector
std::vector<int> SinglyLinkedList::getValues() const {
  std::vector<int> values;
  SinglyNode *currNode = _startNode;
  while (currNode) {
    values.push_back(currNode->val);
    currNode = currNode->next;
  }
  return values;
}

} // namespace ak_algos
