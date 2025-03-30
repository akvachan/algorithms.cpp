#include <vector>

namespace ak_algos {

void bubbleSort(std::vector<int> &array) {
  for (size_t i = 0; i < array.size(); i++) 
    for (size_t j = 0; j < array.size() - 1 - i; j++) 
      if(array[i] > array[j + 1])
        std::swap(array[i], array[j]);
}

} // namespace ak_algos
