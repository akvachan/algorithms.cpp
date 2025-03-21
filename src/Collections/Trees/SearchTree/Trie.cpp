#include "TrieNode.hpp"

#include <iostream>
#include <string_view>

namespace ak_algos {

struct TrieWord {
  std::string word;
  std::optional<int> score;
};

class Trie {
public:
  Trie() : _root(new TrieNode()) {}

  // ~Trie() {
  //   // clean up the whole trie before deleting the root!!!
  //   delete _root;
  // }
  inline size_t getSize() const { return _size; }

  std::optional<int> search(const std::string_view &key) const {
    TrieNode *node = _root;
    for (const char c : key) {
      if (!node->getChild(c))
        return {};
      node = node->getChild(c);
    }
    return node->isTerminal() ? node->getScore() : std::optional<int>{};
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
      if (!node->getChild(c)) {
        node->addChild(new TrieNode{c});
      }
      node = node->getChild(c);
    }
    node->setTerminal(true);
    node->setScore(score);
    _size++;
  }

  void insert(const std::string_view &key) {
    TrieNode *node = _root;
    for (const char c : key) {
      if (!node->getChild(c)) {
        node->addChild(new TrieNode{c});
      }
      node = node->getChild(c);
    }
    node->setTerminal(true);
    _size++;
  }

  int remove(const std::string_view &key) {
    for (const char &c : key) {
      // TODO
      std::cout << c << std::endl;
    }
    _size--;
    return 0;
  }

  std::vector<TrieWord> traverse() const {
    std::vector<TrieWord> results;
    std::string str = "";
    results.reserve(_size);
    _traverseHelper(_root, str, results);
    return results;
  }

private:
  TrieNode *_root;
  size_t _size;

  void _traverseHelper(TrieNode *currentNode, std::string &baseString,
                       std::vector<TrieWord> &results) const {

    if (!currentNode->hasChildren()) {
      results.emplace_back(baseString, currentNode->getScore());
      return;
    }

    if (currentNode->isTerminal()) {
      results.emplace_back(baseString, currentNode->getScore());
    }

    for (TrieNode *childNode : currentNode->getChildren()) {
      if (childNode) {
        if (childNode->getValue() != '\0') {
          std::string str = baseString + childNode->getValue();
          _traverseHelper(childNode, str, results);
        } else {
          _traverseHelper(childNode, baseString, results);
        }
      }
    }
  }
};

} // namespace ak_algos
