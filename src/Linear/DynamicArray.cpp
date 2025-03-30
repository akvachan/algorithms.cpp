#include "DynamicArray.hpp"

// Constructor
namespace ak_algos {

DynamicArray::DynamicArray(int capacity)
    : _length(0), _capacity(capacity), _array(new int[capacity]()) {}

// Destructor
DynamicArray::~DynamicArray() { delete[] _array; }

// Copy Constructor
DynamicArray::DynamicArray(const DynamicArray &other)
    : _length(other._length), _capacity(other._capacity),
      _array(new int[other._capacity]()) {
  for (int i = 0; i < _length; ++i) {
    _array[i] = other._array[i];
  }
}

// Copy Assignment Operator
DynamicArray &DynamicArray::operator=(const DynamicArray &other) {
  if (this == &other)
    return *this;

  int *newArray = new int[other._capacity]();
  for (int i = 0; i < other._length; ++i) {
    newArray[i] = other._array[i];
  }

  delete[] _array;

  _length = other._length;
  _capacity = other._capacity;
  _array = newArray;

  return *this;
}

// Move Constructor
DynamicArray::DynamicArray(DynamicArray &&other) noexcept
    : _length(other._length), _capacity(other._capacity), _array(other._array) {
  other._length = 0;
  other._capacity = 0;
  other._array = nullptr;
}

// Move Assignment Operator
DynamicArray &DynamicArray::operator=(DynamicArray &&other) noexcept {
  if (this == &other)
    return *this;

  delete[] _array;

  _length = other._length;
  _capacity = other._capacity;
  _array = other._array;

  other._length = 0;
  other._capacity = 0;
  other._array = nullptr;

  return *this;
}

// Iterator Definitions
DynamicArray::iterator DynamicArray::begin() { return _array; }

DynamicArray::iterator DynamicArray::end() { return _array + _length; }

DynamicArray::const_iterator DynamicArray::begin() const { return _array; }

DynamicArray::const_iterator DynamicArray::end() const {
  return _array + _length;
}

DynamicArray::const_iterator DynamicArray::cbegin() const { return _array; }

DynamicArray::const_iterator DynamicArray::cend() const {
  return _array + _length;
}

// Element Access
int DynamicArray::get(int i) const { return _array[i]; }

void DynamicArray::set(int i, int n) { _array[i] = n; }

int &DynamicArray::operator[](int i) { return _array[i]; }

const int &DynamicArray::operator[](int i) const { return _array[i]; }

// Modification
void DynamicArray::append(int n) {
  if (_length == _capacity)
    resize();
  _array[_length++] = n;
}

int DynamicArray::pop() { return _array[--_length]; }

void DynamicArray::resize() {
  int newCapacity = _capacity * 2;
  int *newArray = new int[newCapacity]();

  for (int i = 0; i < _length; i++)
    newArray[i] = _array[i];

  delete[] _array;

  _array = newArray;
  _capacity = newCapacity;
}

// Size and Capacity
int DynamicArray::getLength() const { return _length; }

int DynamicArray::getCapacity() const { return _capacity; }

} // namespace ak_algos
