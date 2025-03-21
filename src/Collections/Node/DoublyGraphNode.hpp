#ifndef DOUBLYGRAPHNODE_H
#define DOUBLYGRAPHNODE_H

#include <vector>
#include <memory>

namespace ak_algos {

/**
 * @class GraphNode
 * @brief Represents a node in a doubly-linked graph structure.
 */
class DoublyGraphNode: public std::enable_shared_from_this<DoublyGraphNode> {
public:
    /**
     * @brief Constructs a graph node with a given value.
     * @param val The integer value of the node.
     */
    explicit DoublyGraphNode(int val) : _value(val) {}

    /**
     * @brief Adds a child node to this node and sets parent reference.
     * @param child A shared pointer to the child node.
     */
    void addChild(std::shared_ptr<DoublyGraphNode> child) {
        child->_parent = getSharedPtr();
        _children.push_back(child);
    }

    /**
     * @brief Gets the value of the node.
     * @return The integer value of the node.
     */
    int getValue() const { return _value; }

    /**
     * @brief Gets the parent node.
     * @return A shared pointer to the parent node, or nullptr if root.
     */
    std::shared_ptr<DoublyGraphNode> getParent() const {
        return _parent.lock();
    }

    /**
     * @brief Gets the children of this node.
     * @return A reference to the vector of child nodes.
     */
    const std::vector<std::shared_ptr<DoublyGraphNode>>& getChildren() const {
        return _children;
    }

    std::shared_ptr<DoublyGraphNode> getSharedPtr() {
        return shared_from_this();
    }

private:
    int _value;
    std::weak_ptr<DoublyGraphNode> _parent;  
    std::vector<std::shared_ptr<DoublyGraphNode>> _children;  
};

} // namespace ak_algos

#endif // DOUBLYGRAPHNODE_H
