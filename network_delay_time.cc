class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> g(n + 1);

    for (auto& t : times) {
      g[t[0]].push_back({t[1], t[2]});
    }

    vector<bool> visited(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push({0, k});

    int ans = 0;
    while (!pq.empty()) {
      auto [dis, node] = pq.top();
      pq.pop();

      if (visited[node]) {
        continue;
      }
      visited[node] = true;

      ans = dis;

      for (auto& [next, d] : g[node]) {
        pq.push({dis + d, next});
      }
    }

    for (int i = 1; i <= n; ++i) {
      if (!visited[i]) {
        return -1;
      }
    }

    return ans;
  }
};
// Runtime: 190 ms, faster than 37.41%
// Memory Usage: 42 MB, less than 49.20%
// 2022.4.29 at 茗筑美嘉