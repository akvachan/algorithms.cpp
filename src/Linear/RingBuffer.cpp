#include "RingBuffer.hpp"
#include <stdexcept> // For std::underflow_error

namespace ak_algos {

// Constructor: Initializes the ring buffer with a given capacity
RingBuffer::RingBuffer(int cap)
    : _size(0), _cap(cap), _readIdx(0), _writeIdx(0), _buf(new int[cap]()) { // Initialize buffer to zero
    if (cap <= 0) {
        throw std::invalid_argument("Capacity must be greater than zero.");
    }
}

// Destructor: Releases allocated memory
RingBuffer::~RingBuffer() {
    delete[] _buf;
}

// Returns the current number of elements in the buffer
int RingBuffer::getSize() const {
    return _size;
}

// Returns the capacity of the buffer
int RingBuffer::getCap() const {
    return _cap;
}

// Enqueues a new value into the buffer, overwriting the oldest element if full
void RingBuffer::enque(int val) {
    _buf[_writeIdx] = val;
    _writeIdx = (_writeIdx + 1) % _cap;
    
    if (_size == _cap) {
        // Buffer is full; overwrite the oldest element by advancing _readIdx
        _readIdx = (_readIdx + 1) % _cap;
    } else {
        _size++;
    }
}

// Dequeues the oldest value from the buffer
int RingBuffer::deque() {
    if (_size == 0) {
        throw std::underflow_error("Buffer is empty");
    }
    int val = _buf[_readIdx];
    _buf[_readIdx] = 0; // Optional: Reset the dequeued position
    _readIdx = (_readIdx + 1) % _cap;
    _size--;
    return val;
}

} // namespace ak_algos
