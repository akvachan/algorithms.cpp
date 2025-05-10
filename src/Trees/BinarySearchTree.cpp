#include "BinarySearchTree.hpp"

#include <queue>

namespace ak_algos {

// Constructor
BinarySearchTree::BinarySearchTree() : _root(nullptr) {}

// Destructor
BinarySearchTree::~BinarySearchTree() {
    _clear(_root);
}

// Copy Constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &other) : _root(nullptr) {
    _root = _copyHelper(other._root);
}

// Move Constructor
BinarySearchTree::BinarySearchTree(BinarySearchTree &&other) noexcept : _root(other._root) {
    other._root = nullptr;
}

// Copy Assignment Operator
BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &other) {
    if (this == &other)
        return *this;

    _clear(_root);
    _root = _copyHelper(other._root);

    return *this;
}

// Move Assignment Operator
BinarySearchTree &BinarySearchTree::operator=(BinarySearchTree &&other) noexcept {
    if (this == &other)
        return *this;

    _clear(_root);
    _root = other._root;
    other._root = nullptr;

    return *this;
}

// Traverse method
std::vector<int> BinarySearchTree::traverse() const {
    std::vector<int> path;
    _traverseHelper(_root, path);
    return path;
}

// Find method
bool BinarySearchTree::find(int value) const {
    BinaryNode *currentNode = _root;

    while (currentNode) {
        if (currentNode->val > value)
            currentNode = currentNode->left;
        else if (currentNode->val < value)
            currentNode = currentNode->right;
        else
            return true;
    }

    return false;
}

// Insert method
void BinarySearchTree::insert(int value) {
    BinaryNode *newNode = new BinaryNode{value};
    if (!_root) {
        _root = newNode;
        return;
    }

    BinaryNode *currentNode = _root;

    while (currentNode) {
        if (currentNode->val > value) {
            if (!currentNode->left) {
                currentNode->left = newNode;
                break;
            }
            currentNode = currentNode->left;
        } else {
            if (!currentNode->right) {
                currentNode->right = newNode;
                break;
            }
            currentNode = currentNode->right;
        }
    }
}

// Remove method 
void BinarySearchTree::remove(int value) {
    BinaryNode *currentNode = _root;
    BinaryNode *previousNode = nullptr;

    // Find the node to remove and its parent
    while (currentNode && currentNode->val != value) {
        previousNode = currentNode;
        if (currentNode->val > value)
            currentNode = currentNode->left;
        else
            currentNode = currentNode->right;
    }

    // Value not found in the tree
    if (!currentNode)
        return;

    // Case 1: Node has both children 
    if (currentNode->left && currentNode->right) {
        BinaryNode *smallestChild = _getSmallestChild(currentNode);
        if (smallestChild) {
            currentNode->val = smallestChild->val;
            delete smallestChild;
        }
        return;
    }

    // Case 2: Node has only left child
    if (currentNode->left) {
        if (!previousNode) {
            _root = currentNode->left;
        } else if (previousNode->left == currentNode) {
            previousNode->left = currentNode->left;
        } else {
            previousNode->right = currentNode->left;
        }
        delete currentNode;
        return;
    }

    // Case 3: Node has only right child
    if (currentNode->right) {
        if (!previousNode) {
            _root = currentNode->right;
        } else if (previousNode->left == currentNode) {
            previousNode->left = currentNode->right;
        } else {
            previousNode->right = currentNode->right;
        }
        delete currentNode;
        return;
    }

    // Case 4: Node has no children
    if (!previousNode) {
        _root = nullptr;
    } else if (previousNode->left == currentNode) {
        previousNode->left = nullptr;
    } else {
        previousNode->right = nullptr;
    }
    delete currentNode;
}

BinaryNode* BinarySearchTree::_getLargestChild(BinaryNode *node) const {
    if (!node->left)
        return nullptr;

    BinaryNode *current = node->left;
    BinaryNode *parent = node;

    while (current->right) {
        parent = current;
        current = current->right;
    }

    if (parent != node) {
        parent->right = current->left;
    } else {
        parent->left = current->left;
    }

    return current;
}

BinaryNode* BinarySearchTree::_getSmallestChild(BinaryNode *node) const {
    if (!node->right)
        return nullptr;

    BinaryNode *current = node->right;
    BinaryNode *parent = node;

    while (current->left) {
        parent = current;
        current = current->left;
    }

    if (parent != node) {
        parent->left = current->right;
    } else {
        parent->right = current->right;
    }

    return current;
}

void BinarySearchTree::_clear(BinaryNode *node) {
    if (!node)
        return;

    std::queue<BinaryNode *> queue;
    queue.push(node);

    while (!queue.empty()) {
        BinaryNode *current = queue.front();
        queue.pop();

        if (current->left)
            queue.push(current->left);
        if (current->right)
            queue.push(current->right);

        delete current;
    }
}

void BinarySearchTree::_traverseHelper(BinaryNode *node, std::vector<int> &path) const {
    if (!node)
        return;

    _traverseHelper(node->left, path);
    path.push_back(node->val);
    _traverseHelper(node->right, path);
}

BinaryNode* BinarySearchTree::_copyHelper(BinaryNode *node) {
    if (!node)
        return nullptr;

    BinaryNode *newNode = new BinaryNode{node->val};
    newNode->left = _copyHelper(node->left);
    newNode->right = _copyHelper(node->right);
    return newNode;
}

} // namespace ak_algos
