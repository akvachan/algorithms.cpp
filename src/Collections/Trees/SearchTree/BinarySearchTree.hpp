#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include "BinaryNode.hpp"

#include <vector>

namespace ak_algos {

/**
 * @brief A Binary Search Tree (BST) implementation.
 * 
 * This class provides functionalities to insert, remove, find, and traverse elements
 * in a binary search tree. It supports copy and move semantics for efficient memory management.
 */
class BinarySearchTree {

public:
    // Constructor
    BinarySearchTree();

    // Destructor
    ~BinarySearchTree();

    // Copy Constructor
    BinarySearchTree(const BinarySearchTree &other);

    // Move Constructor
    BinarySearchTree(BinarySearchTree &&other) noexcept;

    // Copy Assignment Operator
    BinarySearchTree &operator=(const BinarySearchTree &other);

    // Move Assignment Operator
    BinarySearchTree &operator=(BinarySearchTree &&other) noexcept;

    /**
     * @brief Traverse the tree using in-order depth-first search.
     * 
     * Saves the value of each node in the provided vector.
     * 
     * @param path A reference to a vector where the traversal path will be stored.
     */
    std::vector<int> traverse() const;

    /**
     * @brief Check if a value exists in the tree.
     * 
     * @param value The integer value to search for.
     * @return true If the value exists in the tree.
     * @return false Otherwise.
     */
    bool find(int value) const;

    /**
     * @brief Insert a value into the tree.
     * 
     * Automatically places the value in the correct position to maintain BST properties.
     * 
     * @param value The integer value to insert.
     */
    void insert(int value);

    /**
     * @brief Remove a value from the tree.
     * 
     * Removes the first occurrence of the specified value or multiple duplicates if they exist.
     * 
     * @param value The integer value to remove.
     */
    void remove(int value);

private:
    BinaryNode *_root; 

    /**
     * @brief Find the largest child in the left subtree.
     * 
     * @param node The node whose left subtree will be searched.
     * @return BinaryNode* Pointer to the largest child node.
     */
    BinaryNode *_getLargestChild(BinaryNode *node) const;

    /**
     * @brief Find the smallest child in the right subtree.
     * 
     * @param node The node whose right subtree will be searched.
     * @return BinaryNode* Pointer to the smallest child node.
     */
    BinaryNode *_getSmallestChild(BinaryNode *node) const;

    /**
     * @brief Delete every node in the tree.
     * 
     * Utilizes an iterative approach with a stack to avoid stack overflow in deep trees.
     * 
     * @param node Pointer to the current node being deleted.
     */
    void _clear(BinaryNode *node);

    /**
     * @brief Helper method for in-order traversal.
     * 
     * Recursively traverses the tree and appends node values to the path vector.
     * 
     * @param node Pointer to the current node being traversed.
     * @param path Reference to the vector storing the traversal path.
     */
    void _traverseHelper(BinaryNode *node, std::vector<int> &path) const;

    /**
     * @brief Helper method for deep copying the tree.
     * 
     * Recursively copies each node from the source tree to the new tree.
     * 
     * @param node Pointer to the current node being copied.
     * @return BinaryNode* Pointer to the newly copied node.
     */
    BinaryNode *_copyHelper(BinaryNode *node);
};

} // namespace ak_algos

#endif // BINARYSEARCHTREE_HPP
