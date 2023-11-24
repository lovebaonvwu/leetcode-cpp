class Solution {
 public:
  int numBusesToDestination(vector<vector<int>>& routes,
                            int source,
                            int target) {
    if (source == target) {
      return 0;
    }

    unordered_map<int, vector<int>> g;
    int n = routes.size();
    for (int i = 0; i < n; ++i) {
      for (auto& r : routes[i]) {
        g[r].push_back(i);
      }
    }

    queue<int> q;
    vector<bool> visited(n);

    for (auto r : g[source]) {
      q.push(r);
      visited[r] = true;
    }

    int ans = 1;
    while (!q.empty()) {
      int cnt = q.size();
      while (cnt-- > 0) {
        auto r = q.front();
        q.pop();
        for (auto cur : routes[r]) {
          if (cur == target) {
            return ans;
          }

          for (auto next : g[cur]) {
            if (!visited[next]) {
              q.push(next);
              visited[next] = true;
            }
          }
        }
      }
      ++ans;
    }

    return -1;
  }
};
// 560ms
// 55.42MB