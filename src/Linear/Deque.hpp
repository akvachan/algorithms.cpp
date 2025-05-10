#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "DoublyNode.hpp"

namespace ak_algos {

class Deque {
public:
    // Constructor
    Deque();

    // Destructor
    ~Deque();

    // Copy Constructor
    Deque(const Deque &other);

    // Copy Assignment Operator
    Deque &operator=(const Deque &other);

    // Move Constructor
    Deque(Deque &&other) noexcept;

    // Move Assignment Operator
    Deque &operator=(Deque &&other) noexcept;

    // Push Methods
    void pushBack(int val);
    void pushFront(int val);

    // Pop Methods
    int popBack();
    int popFront();

    // Accessor Methods
    int front() const;
    int back() const;

private:
    int _length;
    DoublyNode *_startNode;
    DoublyNode *_endNode;
};

} // namespace ak_algos

#endif // DEQUE_HPP
