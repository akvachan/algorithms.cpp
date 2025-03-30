#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <vector>

namespace ak_algos {

/**
 * @brief Sorts a vector of integers in ascending order using the QuickSort algorithm.
 * 
 * This function performs an in-place QuickSort on the provided vector. It utilizes the
 * median-of-three method for pivot selection to improve performance on certain datasets.
 * 
 * @param array A reference to the vector of integers to be sorted.
 */
void quickSort(std::vector<int> &array);

} // namespace ak_algos

#endif // QUICKSORT_HPP
