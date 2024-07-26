class Solution {
 public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<pair<int, int>>> g(n);
    for (auto& e : edges) {
      g[e[0]].push_back({e[1], e[2]});
      g[e[1]].push_back({e[0], e[2]});
    }

    function<int(int)> bfs = [&](int i) -> int {
      vector<int> dists(n, INT_MAX);
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
      pq.push({0, i});
      dists[i] = 0;

      while (!pq.empty()) {
        auto [d, cur] = pq.top();
        pq.pop();

        for (auto& [next, w] : g[cur]) {
          int newDist = d + w;
          if (newDist <= distanceThreshold && newDist < dists[next]) {
            dists[next] = newDist;
            pq.push({newDist, next});
          }
        }
      }

      return count_if(begin(dists), end(dists),
                      [](int d) { return d != INT_MAX; });
    };

    int ans = 0;
    int allTimeMin = INT_MAX;
    for (int i = 0; i < n; ++i) {
      int curMin = bfs(i);
      if (curMin <= allTimeMin) {
        allTimeMin = curMin;
        ans = i;
      }
    }

    return ans;
  }
};
// 40 ms
// 19.51 MB
