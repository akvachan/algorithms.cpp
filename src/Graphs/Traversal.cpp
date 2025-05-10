#include "Traversal.hpp"
#include <queue>
#include <stack>

namespace ak_algos {

void breadthSearch(AdjacencyMatrix graph, std::vector<int>& path, int origin, int target) {
  std::vector<bool> seen(graph.size(), false);
  std::vector<int> prev(graph.size(), -1);
  std::queue<int> q;

  seen[origin] = true;
  q.push(origin);

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    if (curr == target) {
      std::stack<int> s;
      for (int at = target; at != -1; at = prev[at])
        s.push(at);
      while (!s.empty()) {
        path.push_back(s.top());
        s.pop();
      }
      return;
    }

    for (size_t i = 0; i < graph[curr].size(); ++i) {
      if (graph[curr][i] != 0.0f && !seen[i]) {
        seen[i] = true;
        prev[i] = curr;
        q.push(i);
      }
    }
  }
}

} // namespace ak_algos
