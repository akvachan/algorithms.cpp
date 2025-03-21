#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <vector>
#include <memory>

namespace ak_algos {

/**
 * @class GraphNode
 * @brief Represents a node in a graph with dynamic memory management.
 */
class GraphNode {
public:
    /**
     * @brief Constructs a graph node with a given value.
     * @param val The integer value of the node.
     */
    explicit GraphNode(int val) : val(val) {}

    // Move constructor
    GraphNode(GraphNode&& other) noexcept 
        : val(other.val), children(std::move(other.children)) {}

    // Move assignment operator
    GraphNode& operator=(GraphNode&& other) noexcept {
        if (this != &other) {
            val = other.val;
            children = std::move(other.children);
        }
        return *this;
    }

    /**
     * @brief Adds a child node to this node.
     * @param child A unique pointer to the child node.
     */
    void addChild(std::unique_ptr<GraphNode> child) {
        children.push_back(std::move(child));
    }

    /**
     * @brief Gets the value of the node.
     * @return The integer value of the node.
     */
    int getValue() const { return val; }

    /**
     * @brief Gets the children of this node.
     * @return A reference to the vector of child nodes.
     */
    const std::vector<std::unique_ptr<GraphNode>>& getChildren() const {
        return children;
    }

private:
    int val;
    std::vector<std::unique_ptr<GraphNode>> children;
};

} // namespace ak_algos

#endif // GRAPHNODE_H
