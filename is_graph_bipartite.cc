class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    vector<int> color(graph.size());

    queue<int> q;

    for (int i = 0; i < graph.size(); ++i) {
      if (color[i]) {
        continue;
      }

      color[i] = 1;

      for (q.push(i); !q.empty(); q.pop()) {
        auto cur = q.front();

        for (auto neighbor : graph[cur]) {
          if (!color[neighbor]) {
            color[neighbor] = -color[cur];
            q.push(neighbor);
          } else if (color[neighbor] == color[cur]) {
            return false;
          }
        }
      }
    }

    return true;
  }
};
// Runtime: 24 ms, faster than 84.42%
// Memory Usage: 13.5 MB, less than 72.91%