#ifndef TRAVERSAL_HPP
#define TRAVERSAL_HPP

#include <vector>

namespace ak_algos {

typedef std::vector<std::vector<float>> AdjacencyMatrix;

/**
 * Performs a breadth-first search (BFS) on the given graph from origin to
 * target. If a path exists, it is stored in the `path` vector.
 *
 * @param graph Adjacency matrix representing the graph.
 * @param path Vector to store the path from origin to target, if it exists.
 * @param origin Starting node.
 * @param target Target node to reach.
 */
void breadthSearch(AdjacencyMatrix graph, std::vector<int> &path, int origin,
                   int target);

} // namespace ak_algos

#endif // TRAVERSAL_HPP
