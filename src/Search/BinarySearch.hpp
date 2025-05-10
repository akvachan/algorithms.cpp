#ifndef BINARYSEARCH_HPP
#define BINARYSEARCH_HPP

#include <array>
#include <iterator>
#include <optional>
#include <string>
#include <vector>

namespace ak_algos {

/**
 * @brief Generic binary search using iterators.
 * @return Optional index of the target if found.
 */
template <typename RandomIt, typename T>
std::optional<size_t> binarySearch(RandomIt begin, RandomIt end,
                                   const T &target) {
  auto left = begin;
  auto right = end;

  while (left < right) {
    auto mid = left + (right - left) / 2;
    if (*mid == target) {
      return std::distance(begin, mid);
    } else if (*mid < target) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return std::nullopt;
}

/**
 * @brief Overload for std::vector
 */
template <typename T>
inline std::optional<size_t> binarySearch(const std::vector<T> &vec,
                                          const T &target) {
  return binarySearch(vec.begin(), vec.end(), target);
}

/**
 * @brief Overload for std::array
 */
template <typename T, size_t N>
inline std::optional<size_t> binarySearch(const std::array<T, N> &arr,
                                          const T &target) {
  return binarySearch(arr.begin(), arr.end(), target);
}

/**
 * @brief Overload for std::string to search for a character
 */
inline std::optional<size_t> binarySearch(const std::string &str, char target) {
  return binarySearch(str.begin(), str.end(), target);
}

} // namespace ak_algos

#endif // BINARYSEARCH_HPP
