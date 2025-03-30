#include <vector>
#include <algorithm>

namespace ak_algos {

void insertionSort(std::vector<int> &array) {
  for (size_t i = 1; i < array.size(); i++) {
    size_t j = i;
    while (j > 0 && array[j-1] > array[j]) {
      std::swap(array[j], array[j-1]);
      j--;
    } 
  }
}

} // namespace ak_algos
