#include "Trie.hpp"

namespace ak_algos {

Trie::Trie() : _root(new TrieNode()), _keysCount(0) {}

Trie::~Trie() {
  delete _root; // TrieNode destructor handles recursive deletion
}

Trie::Trie(const Trie &other) : _root(nullptr), _keysCount(other._keysCount) {
  _root = _cloneSubtree(other._root);
}

Trie &Trie::operator=(const Trie &other) {
  if (this != &other) {
    delete _root;
    _root = _cloneSubtree(other._root);
    _keysCount = other._keysCount;
  }
  return *this;
}

Trie::Trie(Trie &&other) noexcept
    : _root(other._root), _keysCount(other._keysCount) {
  other._root = nullptr;
  other._keysCount = 0;
}

Trie &Trie::operator=(Trie &&other) noexcept {
  if (this != &other) {
    delete _root;
    _root = other._root;
    _keysCount = other._keysCount;
    other._root = nullptr;
    other._keysCount = 0;
  }
  return *this;
}

size_t Trie::getKeysCount() const { return _keysCount; }

std::optional<int> Trie::getScore(const std::string_view &key) const {
  TrieNode *node = _root;
  for (char c : key) {
    if (!node->getChild(c))
      return {};
    node = node->getChild(c);
  }
  return node->isTerminal() ? node->getScore() : std::optional<int>{};
}

bool Trie::search(const std::string_view &key) const {
  TrieNode *node = _root;
  for (char c : key) {
    if (!node->getChild(c))
      return false;
    node = node->getChild(c);
  }
  return node->isTerminal();
}

std::vector<TrieWord> Trie::complete(const std::string_view &prefix) const {
  std::vector<TrieWord> results;
  std::string baseString;
  TrieNode *node = _root;

  for (char c : prefix) {
    if (!node->getChild(c))
      return results;
    node = node->getChild(c);
    baseString += c;
  }

  _traverseHelper(node, baseString, results);
  return results;
}

void Trie::insert(const std::string_view &key, int score) {
  TrieNode *node = _root;
  for (char c : key) {
    if (!node->getChild(c))
      node->addChild(new TrieNode{c});
    node = node->getChild(c);
  }

  if (!node->isTerminal())
    _keysCount++;
  node->setTerminal(true);
  node->setScore(score);
}

void Trie::insert(const std::string_view &key) {
  TrieNode *node = _root;
  for (char c : key) {
    if (!node->getChild(c))
      node->addChild(new TrieNode{c});
    node = node->getChild(c);
  }

  if (!node->isTerminal())
    _keysCount++;
  node->setTerminal(true);
}

void Trie::remove(const std::string_view &key) { _removeHelper(_root, key); }

std::vector<TrieWord> Trie::traverse() const {
  std::vector<TrieWord> results;
  std::string str = "";
  results.reserve(_keysCount);
  _traverseHelper(_root, str, results);
  return results;
}

void Trie::_removeHelper(TrieNode *currentNode, const std::string_view &key,
                         size_t depth) {
  if (!currentNode)
    return;

  if (depth == key.size()) {
    if (currentNode->isTerminal()) {
      currentNode->setTerminal(false);
      _keysCount--;
    }
    return;
  }

  TrieNode *nextNode = currentNode->getChild(key[depth]);
  if (nextNode) {
    _removeHelper(nextNode, key, depth + 1);
  }
}

void Trie::_traverseHelper(TrieNode *currentNode, std::string &baseString,
                           std::vector<TrieWord> &results) const {
  if (!currentNode)
    return;

  if (currentNode->isTerminal()) {
    results.emplace_back(baseString, currentNode->getScore());
  }

  for (TrieNode *childNode : currentNode->getChildren()) {
    if (childNode) {
      std::string newBaseString = baseString + childNode->getValue();
      _traverseHelper(childNode, newBaseString, results);
    }
  }
}

TrieNode *Trie::_cloneSubtree(const TrieNode *node) const {
  if (!node)
    return nullptr;

  TrieNode *newNode = new TrieNode(node->getValue());
  newNode->setTerminal(node->isTerminal());
  if (node->isTerminal() && node->getScore())
    newNode->setScore(*node->getScore());

  for (TrieNode *child : node->getChildren()) {
    if (child)
      newNode->addChild(_cloneSubtree(child));
  }
  return newNode;
}

} // namespace ak_algos
