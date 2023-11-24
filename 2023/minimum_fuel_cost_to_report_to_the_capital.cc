class Solution {
  unordered_map<int, vector<int>> g;
  unordered_set<int> visited;
  long long ans = 0;

 public:
  long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    for (auto& road : roads) {
      g[road[0]].push_back(road[1]);
      g[road[1]].push_back(road[0]);
    }

    dfs(0, seats);

    return ans;
  }

  long long dfs(int cur, int seats) {
    long long people = 1;

    visited.insert(cur);

    for (auto& next : g[cur]) {
      if (visited.find(next) == visited.end()) {
        people += dfs(next, seats);
      }
    }

    if (cur != 0) {
      ans += (people + seats - 1) / seats;
    }

    return people;
  }
};
// Runtime 895 ms
// Memory 260.7 MB
// 2023.2.12 at 茗筑美嘉