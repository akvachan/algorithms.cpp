#include "Deque.hpp"

namespace ak_algos {

// Constructor
Deque::Deque() : _len(0), _startNode(nullptr), _endNode(nullptr) {}

// Destructor
Deque::~Deque() {
    while (_startNode != nullptr) {
        DoublyNode *temp = _startNode;
        _startNode = _startNode->next;
        delete temp;
    }
    _endNode = nullptr;
    _len = 0;
}

// Copy Constructor
Deque::Deque(const Deque &other) : _len(0), _startNode(nullptr), _endNode(nullptr) {
    DoublyNode *current = other._startNode;
    while (current != nullptr) {
        pushBack(current->val);
        current = current->next;
    }
}

// Copy Assignment Operator
Deque &Deque::operator=(const Deque &other) {
    if (this != &other) {
        // Clear existing nodes
        while (_startNode != nullptr) {
            DoublyNode *temp = _startNode;
            _startNode = _startNode->next;
            delete temp;
        }
        _endNode = nullptr;
        _len = 0;

        // Copy nodes from other
        DoublyNode *current = other._startNode;
        while (current != nullptr) {
            pushBack(current->val);
            current = current->next;
        }
    }
    return *this;
}

// Move Constructor
Deque::Deque(Deque &&other) noexcept
    : _len(other._len), _startNode(other._startNode), _endNode(other._endNode) {
    other._len = 0;
    other._startNode = nullptr;
    other._endNode = nullptr;
}

// Move Assignment Operator
Deque &Deque::operator=(Deque &&other) noexcept {
    if (this != &other) {
        // Clear existing nodes
        while (_startNode != nullptr) {
            DoublyNode *temp = _startNode;
            _startNode = _startNode->next;
            delete temp;
        }

        // Transfer ownership
        _len = other._len;
        _startNode = other._startNode;
        _endNode = other._endNode;

        // Nullify the other
        other._len = 0;
        other._startNode = nullptr;
        other._endNode = nullptr;
    }
    return *this;
}

// Push Back
void Deque::pushBack(int val) {
    DoublyNode *newNode = new DoublyNode{_endNode, nullptr, val};

    // Check if end node already exists and if so, make its next node new
    if (_endNode)
        _endNode->next = newNode;

    _endNode = newNode;

    // If new node is the first node, then it is also a start node
    if (_len == 0)
        _startNode = _endNode;

    _len++;
}

// Push Front
void Deque::pushFront(int val) {
    DoublyNode *newNode = new DoublyNode{nullptr, _startNode, val};

    // Check if start node already exists and if so, make its preceding node new
    if (_startNode)
        _startNode->prev = newNode;

    _startNode = newNode;

    // If new node is the first node, then it is also an end node
    if (_len == 0)
        _endNode = _startNode;

    _len++;
}

// Pop Back
int Deque::popBack() {
    if (_len == 0)
      return -1;

    DoublyNode *tmpNode = _endNode;
    int val = tmpNode->val;
    _endNode = tmpNode->prev;

    if (_endNode) {
        _endNode->next = nullptr;
    }

    if (_len == 1) {
        _startNode = nullptr;
    }

    delete tmpNode;
    _len--;

    return val;
}

// Pop Front
int Deque::popFront() {
    if (_len == 0)
        return -1;

    DoublyNode *tmpNode = _startNode;
    int val = tmpNode->val;
    _startNode = tmpNode->next;

    if (_startNode) {
        _startNode->prev = nullptr; // Corrected condition to check _startNode
    }

    if (_len == 1) {
        _endNode = nullptr;
    }

    delete tmpNode;
    _len--;

    return val;
}

// Front Accessor
int Deque::front() const {
    if (_startNode)
        return _startNode->val;

    return -1;
}

// Back Accessor
int Deque::back() const {
    if (_endNode)
        return _endNode->val;

    return -1;
}

} // namespace ak_algos
