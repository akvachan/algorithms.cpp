#include "DynamicArray.hpp"

// Constructor
namespace ak_algos {

DynamicArray::DynamicArray(int capacity)
    : _size(0), _capacity(capacity), _array(new int[capacity]()) {}

// Destructor
DynamicArray::~DynamicArray() { delete[] _array; }

// Copy Constructor
DynamicArray::DynamicArray(const DynamicArray &other)
    : _size(other._size), _capacity(other._capacity),
      _array(new int[other._capacity]()) {
  for (int i = 0; i < _size; ++i) {
    _array[i] = other._array[i];
  }
}

// Copy Assignment Operator
DynamicArray &DynamicArray::operator=(const DynamicArray &other) {
  if (this == &other)
    return *this;

  int *newArray = new int[other._capacity]();
  for (int i = 0; i < other._size; ++i) {
    newArray[i] = other._array[i];
  }

  delete[] _array;

  _size = other._size;
  _capacity = other._capacity;
  _array = newArray;

  return *this;
}

// Move Constructor
DynamicArray::DynamicArray(DynamicArray &&other) noexcept
    : _size(other._size), _capacity(other._capacity), _array(other._array) {
  other._size = 0;
  other._capacity = 0;
  other._array = nullptr;
}

// Move Assignment Operator
DynamicArray &DynamicArray::operator=(DynamicArray &&other) noexcept {
  if (this == &other)
    return *this;

  delete[] _array;

  _size = other._size;
  _capacity = other._capacity;
  _array = other._array;

  other._size = 0;
  other._capacity = 0;
  other._array = nullptr;

  return *this;
}

// Iterator Definitions
DynamicArray::iterator DynamicArray::begin() { return _array; }

DynamicArray::iterator DynamicArray::end() { return _array + _size; }

DynamicArray::const_iterator DynamicArray::begin() const { return _array; }

DynamicArray::const_iterator DynamicArray::end() const {
  return _array + _size;
}

DynamicArray::const_iterator DynamicArray::cbegin() const { return _array; }

DynamicArray::const_iterator DynamicArray::cend() const {
  return _array + _size;
}

// Element Access
int DynamicArray::get(int i) const { return _array[i]; }

void DynamicArray::set(int i, int n) { _array[i] = n; }

int &DynamicArray::operator[](int i) { return _array[i]; }

const int &DynamicArray::operator[](int i) const { return _array[i]; }

// Modification
void DynamicArray::pushback(int n) {
  if (_size == _capacity)
    resize();
  _array[_size++] = n;
}

int DynamicArray::popback() { return _array[--_size]; }

void DynamicArray::resize() {
  int newCapacity = _capacity * 2;
  int *newArray = new int[newCapacity]();

  for (int i = 0; i < _size; i++)
    newArray[i] = _array[i];

  delete[] _array;

  _array = newArray;
  _capacity = newCapacity;
}

// Size and Capacity
int DynamicArray::getSize() const { return _size; }

int DynamicArray::getCapacity() const { return _capacity; }

} // namespace ak_algos
