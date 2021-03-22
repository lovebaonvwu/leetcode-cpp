class Solution {
 public:
  int findCenter(vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> graph;

    for (auto& e : edges) {
      graph[e[0]].push_back(e[1]);
      graph[e[1]].push_back(e[0]);
    }

    int ans = 0;

    for (auto& g : graph) {
      if (g.second.size() == edges.size()) {
        ans = g.first;
        break;
      }
    }

    return ans;
  }
};
// Runtime: 280 ms, faster than 100.00%
// Memory Usage: 100.5 MB, less than 100.00%