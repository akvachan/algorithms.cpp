#include "RingBuffer.hpp"
#include <stdexcept> // For std::underflow_error

namespace ak_algos {

// Constructor: Initializes the ring buffer with a given capacity
RingBuffer::RingBuffer(int capacity)
    : _length(0), _capacity(capacity), _readIdx(0), _writeIdx(0), _bufferArray(new int[capacity]()) { // Initialize buffer to zero
    if (capacity <= 0) {
        throw std::invalid_argument("Capacity must be greater than zero.");
    }
}

// Destructor: Releases allocated memory
RingBuffer::~RingBuffer() {
    delete[] _bufferArray;
}

// Returns the current number of elements in the buffer
int RingBuffer::getLength() const {
    return _length;
}

// Returns the capacity of the buffer
int RingBuffer::getCapacity() const {
    return _capacity;
}

// Enqueues a new value into the buffer, overwriting the oldest element if full
void RingBuffer::push(int value) {
    _bufferArray[_writeIdx] = value;
    _writeIdx = (_writeIdx + 1) % _capacity;
    
    if (_length == _capacity) {
        // Buffer is full; overwrite the oldest element by advancing _readIdx
        _readIdx = (_readIdx + 1) % _capacity;
    } else {
        _length++;
    }
}

// Dequeues the oldest value from the buffer
int RingBuffer::pop() {
    if (_length == 0) {
        throw std::underflow_error("Buffer is empty");
    }
    int value = _bufferArray[_readIdx];
    _bufferArray[_readIdx] = 0; // Optional: Reset the dequeued position
    _readIdx = (_readIdx + 1) % _capacity;
    _length--;
    return value;
}

} // namespace ak_algos
