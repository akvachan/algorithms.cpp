#ifndef TRIE_HPP
#define TRIE_HPP

#include "TrieNode.hpp"
#include <string>
#include <string_view>
#include <vector>
#include <optional>

namespace ak_algos {

/**
 * @brief A struct representing a word in the Trie along with its optional score.
 */
struct TrieWord {
  std::string word;
  std::optional<int> score;
};

/**
 * @class Trie
 * @brief A Trie data structure for storing strings with optional scores.
 */
class Trie {
public:
  Trie();
  ~Trie();

  // Copy semantics
  Trie(const Trie& other);
  Trie& operator=(const Trie& other);

  // Move semantics
  Trie(Trie&& other) noexcept;
  Trie& operator=(Trie&& other) noexcept;

  /**
   * @brief Returns the number of keys stored in the trie.
   */
  size_t getKeysCount() const;

  /**
   * @brief Retrieves the score associated with a key, if it exists.
   */
  std::optional<int> getScore(const std::string_view &key) const;

  /**
   * @brief Checks whether a key exists in the trie.
   */
  bool search(const std::string_view &key) const;

  /**
   * @brief Returns all words in the trie with the given prefix.
   */
  std::vector<TrieWord> complete(const std::string_view &prefix) const;

  /**
   * @brief Inserts a key with a score.
   */
  void insert(const std::string_view &key, int score);

  /**
   * @brief Inserts a key without a score.
   */
  void insert(const std::string_view &key);

  /**
   * @brief Removes a key from the trie.
   */
  void remove(const std::string_view &key);

  /**
   * @brief Traverses the entire trie and returns all stored words and their scores.
   */
  std::vector<TrieWord> traverse() const;

private:
  TrieNode *_root;
  size_t _keysCount;

  void _removeHelper(TrieNode *currentNode, const std::string_view &key, size_t depth = 0);
  void _traverseHelper(TrieNode *currentNode, std::string &baseString,
                       std::vector<TrieWord> &results) const;

  TrieNode* _cloneSubtree(const TrieNode* node) const;
};

} // namespace ak_algos

#endif // TRIE_HPP
