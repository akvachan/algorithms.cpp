#ifndef BINARY_HEAP_HPP
#define BINARY_HEAP_HPP

#include <vector>
#include <optional>

namespace ak_algos {

/**
 * @class BinaryHeap
 * @brief A Min-Heap implementation using a binary heap data structure.
 */
class BinaryHeap {
public:
  /**
   * @brief Constructs an empty BinaryHeap.
   */
  BinaryHeap();

  /**
   * @brief Inserts a value into the heap while maintaining the heap property.
   * 
   * @param value The integer value to be inserted into the heap.
   * 
   * @note The heap maintains the min-heap property where the smallest element is always at the root.
   * @complexity Time complexity: O(log n), where n is the number of elements in the heap.
   */
  void insert(int value);

  /**
   * @brief Removes and returns the smallest element (root) from the heap.
   * 
   * @return std::optional<int> The smallest element in the heap if available, or an empty optional if the heap is empty.
   * 
   * @note If the heap is empty, an empty optional is returned.
   * @complexity Time complexity: O(log n), where n is the number of elements in the heap.
   */
  std::optional<int> pop();

private:
  /**
   * @brief Internal container to store heap elements.
   * 
   * The vector is used to store elements in a complete binary tree structure.
   */
  std::vector<int> _container;
};

} // namespace ak_algos

#endif // BINARY_HEAP_HPP
