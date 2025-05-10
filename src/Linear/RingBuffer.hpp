#ifndef RINGBUFFER_HPP
#define RINGBUFFER_HPP

#include <cstddef> // For std::size_t

namespace ak_algos {

class RingBuffer {
public:
  // Constructor: Initializes the ring buffer with a given capacity
  explicit RingBuffer(int cap);

  // Destructor: Releases allocated memory
  ~RingBuffer();

  // Delete copy constructor and copy assignment operator to prevent shallow
  // copies
  RingBuffer(const RingBuffer &) = delete;
  RingBuffer &operator=(const RingBuffer &) = delete;

  // Returns the current number of elements in the buffer
  int getLength() const;

  // Returns the capacity of the buffer
  int getCapacity() const;

  // Enqueues a new value into the buffer, overwriting the oldest element if
  // full
  void push(int val);

  // Dequeues the oldest value from the buffer
  // Throws std::underflow_error if the buffer is empty
  int pop();

private:
  int _length;       // Current number of elements
  int _capacity;     // Maximum capacity
  int _readIdx;      // Index for dequeuing
  int _writeIdx;     // Index for enqueueing
  int *_bufferArray; // Pointer to the buffer array
};

} // namespace ak_algos

#endif // RINGBUFFER_HPP
