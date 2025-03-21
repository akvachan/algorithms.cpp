#include "BinaryHeap.hpp"
#include <algorithm>

namespace ak_algos {

BinaryHeap::BinaryHeap() : _container({}) {}

void BinaryHeap::insert(int value) {
  _container.push_back(value);
  int thisIndex = _container.size() - 1;

  while (thisIndex > 0) {
    int parentIndex = (thisIndex - 1) / 2;

    if (_container[thisIndex] >= _container[parentIndex])
      break;

    std::swap(_container[thisIndex], _container[parentIndex]);
    thisIndex = parentIndex;
  }
}

std::optional<int> BinaryHeap::pop() {
  if (_container.empty())
    return {};

  int rootValue = _container[0];
  int lastIndex = _container.size() - 1;

  std::swap(_container[0], _container[lastIndex]);
  _container.pop_back();

  int thisIndex = 0;
  int heapSize = _container.size();

  while (thisIndex < heapSize) {
    int leftChildIndex = 2 * thisIndex + 1;
    int rightChildIndex = 2 * thisIndex + 2;

    if (leftChildIndex >= heapSize)
      break;

    int smallestChildIndex = leftChildIndex;
    if (rightChildIndex < heapSize && _container[rightChildIndex] < _container[leftChildIndex]) {
      smallestChildIndex = rightChildIndex;
    }

    if (_container[thisIndex] <= _container[smallestChildIndex])
      break;

    std::swap(_container[thisIndex], _container[smallestChildIndex]);
    thisIndex = smallestChildIndex;
  }

  return {rootValue};
}

} // namespace ak_algos
