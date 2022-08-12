class Solution {
 public:
  int reachableNodes(int n,
                     vector<vector<int>>& edges,
                     vector<int>& restricted) {
    unordered_map<int, vector<int>> g;
    for (auto& e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }

    unordered_set<int> visited;
    unordered_set<int> res(restricted.begin(), restricted.end());

    queue<int> q;
    q.push(0);
    visited.insert(0);

    int ans = 0;
    while (!q.empty()) {
      int cnt = q.size();

      while (cnt-- > 0) {
        int n = q.front();
        q.pop();
        ++ans;

        for (auto& next : g[n]) {
          if (visited.find(next) != visited.end()) {
            continue;
          }

          if (res.find(next) != res.end()) {
            continue;
          }

          visited.insert(next);
          q.push(next);
        }
      }
    }

    return ans;
  }
};
// Runtime: 779 ms, faster than 22.22%
// Memory Usage: 192.9 MB, less than 11.11%
// 2022.8.12 at 奥盛大厦