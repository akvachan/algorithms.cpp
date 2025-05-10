#ifndef TRIENODE_H
#define TRIENODE_H

#include <array>
#include <optional>

namespace ak_algos {

/**
 * @class TrieNode
 * @brief Represents a node in a trie structure
 */
class TrieNode {
public:
  /**
   * @brief Constructs a trie node with a given value.
   * @param value The char value of the node.
   * @param isTerminal Whether the node marks the end of a word.
   */
  TrieNode(char value, int score, bool isTerminal)
      : _value(value), _score({score}), _isTerminal(isTerminal), _children({}) {
  }

  /**
   * @brief Constructs a trie node with default values.
   */
  TrieNode()
      : _value('\0'), _score(std::optional<int>{}), _isTerminal(false),
        _children({}) {}

  /**
   * @brief Constructs a trie node with value.
   */
  TrieNode(char value)
      : _value(value), _score(std::optional<int>{}), _isTerminal(false),
        _children({}) {}

  // Allow shallow copy operations
  TrieNode(const TrieNode &) = default;
  TrieNode &operator=(const TrieNode &) = default;

  // Move constructor
  TrieNode(TrieNode &&other) noexcept
      : _value(other._value), _score(other._score),
        _isTerminal(other._isTerminal), _children(std::move(other._children)) {}

  // Move assignment operator
  TrieNode &operator=(TrieNode &&other) noexcept {
    if (this != &other) {
      _value = other._value;
      _score = other._score;
      _isTerminal = other._isTerminal;
      _children = std::move(other._children);
    }
    return *this;
  }

  /**
   * @brief Destroys the trie node and deletes all children.
   */
  ~TrieNode() {
    for (TrieNode *child : _children) {
      delete child;
    }
  }

  /**
   * @brief Gets the value of the node.
   * @return The character value of the node.
   */
  char getValue() const { return _value; }

  /**
   * @brief Gets the score of the node, which is either int or {}.
   * @return The character score of the node.
   */
  std::optional<int> getScore() const { return _score; }

  /**
   * @brief Gets the children of this node.
   * @return A reference to the vector of child node pointers.
   */
  const std::array<TrieNode *, 26> &getChildren() const { return _children; }

  /**
   * @brief Gets a pointer to a child node with a given value.
   * @param value The character value to search for.
   * @return A pointer to the child node if found, otherwise nullptr.
   */
  TrieNode *getChild(char value) const {
    size_t alphabetIndex = value - 97;
    if (alphabetIndex < 0 || alphabetIndex > 25)
      return nullptr;
    return _children[alphabetIndex];
  }

  /**
   * @brief Adds a child node to this node.
   * @param child A raw pointer to the child node.
   */
  TrieNode *addChild(TrieNode *child) {
    size_t alphabetIndex = child->_value - 97;
    if (alphabetIndex < 0 || alphabetIndex > 25)
      return nullptr;
    _children[alphabetIndex] = child;
    return child;
  }

  /**
   * @brief Sets node to be terminal
   */
  void setTerminal(const bool isTerminal) { _isTerminal = isTerminal; }

  /**
   * @brief Sets a score for the node
   */
  void setScore(const int score) { _score = {score}; }

  /**
   * @brief Checks if the node is terminal.
   * @return True if node marks the end of a word, false otherwise.
   */
  bool isTerminal() const { return _isTerminal; }

  /**
   * @brief Checks if the node has any children.
   * @return True if the node has children, false otherwise.
   */
  bool hasChildren() const { return !_children.empty(); }

private:
  char _value;                          ///< Character value of the node.
  std::optional<int> _score;            ///< Score for the word.
  bool _isTerminal;                     ///< Flag to mark the end of a word.
  std::array<TrieNode *, 26> _children; ///< Children of this node.
};

} // namespace ak_algos

#endif // TRIENODE_H
