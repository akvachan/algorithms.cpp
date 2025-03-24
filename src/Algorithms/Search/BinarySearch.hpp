#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <array>
#include <optional>
#include <string>
#include <vector>

// This is not optimal!
// TODO Proper implementation using std::iterator.end(), std::iterator.begin()

#define BINARY_SEARCH(CONTAINER, TARGET)                                       \
  size_t beginIdx = 0;                                                         \
  size_t endIdx = CONTAINER.size() - 1;                                        \
  size_t middleIdx = (endIdx + beginIdx) / 2;                                  \
  while (beginIdx < endIdx) {                                                  \
    if (TARGET == CONTAINER[middleIdx])                                        \
      return middleIdx;                                                        \
    else if (TARGET < CONTAINER[middleIdx])                                    \
      endIdx = middleIdx;                                                      \
    else                                                                       \
      beginIdx = middleIdx;                                                    \
    middleIdx = (endIdx + beginIdx) / 2;                                       \
  }                                                                            \
  return {};

namespace ak_algos {

template <typename T, size_t N>
inline std::optional<size_t> binarySearch(std::array<T, N> &array, T target) {
  BINARY_SEARCH(array, target);
}

template <typename T>
inline std::optional<int> binarySearch(std::vector<T> &array, T target) {
  BINARY_SEARCH(array, target);
}

inline std::optional<int> binarySearch(std::string &string, char target) {
  BINARY_SEARCH(string, target);
}

} // namespace ak_algos

#endif
