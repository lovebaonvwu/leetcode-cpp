class Solution {
 public:
  vector<int> minimumTime(int n,
                          vector<vector<int>>& edges,
                          vector<int>& disappear) {
    unordered_map<int, vector<pair<int, int>>> g;
    for (auto& e : edges) {
      g[e[0]].push_back({e[1], e[2]});
      g[e[1]].push_back({e[0], e[2]});
    }

    vector<int> dist(n, INT_MAX);

    priority_queue<pair<int, int>> pq;
    pq.push({0, 0});
    dist[0] = 0;

    vector<int> ans(n, -1);

    while (!pq.empty()) {
      auto [d, node] = pq.top();
      pq.pop();

      ans[node] = d;

      for (auto [neighbor, t] : g[node]) {
        int expectedArrive = d + t;
        if (expectedArrive >= disappear[neighbor])
          continue;

        if (expectedArrive <= dist[neighbor]) {
          dist[neighbor] = expectedArrive;
          pq.push({expectedArrive, neighbor});
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  vector<int> minimumTime(int n,
                          vector<vector<int>>& edges,
                          vector<int>& disappear) {
    unordered_map<int, vector<pair<int, int>>> g;
    for (auto& e : edges) {
      g[e[0]].push_back({e[1], e[2]});
      g[e[1]].push_back({e[0], e[2]});
    }

    vector<int> dist(n, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty()) {
      auto [d, node] = pq.top();
      pq.pop();

      if (dist[node] < d)
        continue;

      for (auto [neighbor, t] : g[node]) {
        int expectedArrive = d + t;
        if (expectedArrive >= disappear[neighbor])
          continue;

        if (expectedArrive < dist[neighbor]) {
          dist[neighbor] = expectedArrive;
          pq.push({expectedArrive, neighbor});
        }
      }
    }

    vector<int> ans(n, -1);
    for (int i = 0; i < n; ++i) {
      if (dist[i] != INT_MAX)
        ans[i] = dist[i];
    }

    return ans;
  }
};