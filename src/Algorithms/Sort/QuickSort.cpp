#include "QuickSort.hpp"

#include <algorithm>
#include <vector>

namespace {

/**
 * @brief Helper function to determine pivot.
 *
 * @param array The array to sort.
 * @param startIdx The starting index of the subarray.
 * @param endIdx The ending index of the subarray.
 */
size_t getPivotIdx(std::vector<int> &array, size_t startIdx, size_t endIdx) {
  size_t mid = startIdx + (endIdx - startIdx) / 2;

  if (array[mid] < array[startIdx])
    std::swap(array[startIdx], array[mid]);
  if (array[endIdx] < array[startIdx])
    std::swap(array[startIdx], array[endIdx]);
  if (array[mid] < array[endIdx])
    std::swap(array[mid], array[endIdx]);

  return endIdx;
}

/**
 * @brief Helper function to perform QuickSort on a subarray.
 *
 * @param array The array to sort.
 * @param startIdx The starting index of the subarray.
 * @param endIdx The ending index of the subarray.
 */
void quickSortHelper(std::vector<int> &array, size_t startIdx, size_t endIdx) {
  if (startIdx >= endIdx)
    return;

  // Median-of-three pivot selection
  size_t pivotIdx = getPivotIdx(array, startIdx, endIdx);
  size_t i = startIdx;

  // Partitioning the array around the pivot
  for (size_t j = startIdx; j < endIdx; ++j)
    if (array[j] < array[pivotIdx])
      std::swap(array[i++], array[j]);
  std::swap(array[i], array[pivotIdx]);

  // Recursively sort the partitions
  if (i > startIdx)
    quickSortHelper(array, startIdx, i - 1);
  if (i + 1 < endIdx)
    quickSortHelper(array, i + 1, endIdx);
}


} // namespace

namespace ak_algos {

/**
 * @brief Public interface to perform QuickSort on an entire array.
 *
 * @param array The array to sort.
 */
void quickSort(std::vector<int> &array) {
  if (!array.empty())
    quickSortHelper(array, 0, array.size() - 1);
}

} // namespace ak_algos
