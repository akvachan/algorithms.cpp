#include "TrieNode.hpp"

#include <string>
#include <string_view>
#include <vector>

namespace ak_algos {

struct TrieWord {
  std::string word;
  std::optional<int> score;
};

class Trie {
public:
  Trie() : _root(new TrieNode()) {}

  // DESTRUCTOR
  // ~Trie() {
  //   // clean up the whole trie before deleting the root!!!
  //   delete _root;
  // }

  // COPY CONSTRUCTOR + ASSIGNMENT, MOVE CONSTRUCTOR + ASSIGNMENT

  inline size_t getKeysCount() const { return _keysCount; }

  std::optional<int> getScore(const std::string_view &key) const {
    TrieNode *node = _root;
    for (const char c : key) {
      if (!node->getChild(c))
        return {};
      node = node->getChild(c);
    }
    return node->isTerminal() ? node->getScore() : std::optional<int>{};
  }

  bool search(const std::string_view &key) const {
    TrieNode *node = _root;
    for (const char c : key) {
      if (!node->getChild(c))
        return {};
      node = node->getChild(c);
    }
    return node->isTerminal();
  }

  std::vector<TrieWord> complete(const std::string_view &prefix) const {
    std::vector<TrieWord> results;
    std::string baseString;

    TrieNode *node = _root;
    for (const char c : prefix) {
      if (!node->getChild(c))
        return results;
      node = node->getChild(c);
      baseString += c;
    }

    _traverseHelper(node, baseString, results);
    return results;
  }

  void insert(const std::string_view &key, const int score) {
    TrieNode *node = _root;
    for (const char c : key) {
      if (!node->getChild(c))
        node->addChild(new TrieNode{c});
      node = node->getChild(c);
    }
    if (!node->isTerminal())
      _keysCount++;
    node->setTerminal(true);
    node->setScore(score);
  }

  void insert(const std::string_view &key) {
    TrieNode *node = _root;
    for (const char c : key) {
      if (!node->getChild(c))
        node->addChild(new TrieNode{c});
      node = node->getChild(c);
    }
    if (!node->isTerminal())
      _keysCount++;
    node->setTerminal(true);
  }

  void remove(const std::string_view &key) { _removeHelper(_root, key); }

  std::vector<TrieWord> traverse() const {
    std::vector<TrieWord> results;
    std::string str = "";
    results.reserve(_keysCount);
    _traverseHelper(_root, str, results);
    return results;
  }

private:
  TrieNode *_root;
  size_t _keysCount;

  void _removeHelper(TrieNode *currentNode, const std::string_view &key,
                     size_t depth = 0) {
    if (depth == key.size()) {
      if (!currentNode->hasChildren()) {
        delete currentNode;
        currentNode = nullptr;
        return;
      }

      if (currentNode->isTerminal()) {
        currentNode->setTerminal(false);
        _keysCount--;
        return;
      }
    }

    currentNode = currentNode->getChild(key[depth]);
    if (currentNode) 
      _removeHelper(currentNode, key, ++depth);

    return;
  }

  void _traverseHelper(TrieNode *currentNode, std::string &baseString,
                       std::vector<TrieWord> &results) const {

    if (!currentNode->hasChildren()) {
      results.emplace_back(baseString, currentNode->getScore());
      return;
    }

    if (currentNode->isTerminal())
      results.emplace_back(baseString, currentNode->getScore());

    for (TrieNode *childNode : currentNode->getChildren()) {
      if (childNode) {
        std::string newBaseString = baseString + childNode->getValue();
        _traverseHelper(childNode, newBaseString, results);
      }
    }
  }
};

} // namespace ak_algos
