class Solution {
 public:
  int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    vector<vector<int>> g(n + 1, vector<int>());
    for (auto& e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }

    vector<int> visited(n + 1, 0);
    vector<int> dists(n + 1, -1);

    queue<pair<int, int>> q;
    q.push({1, 0});
    visited[1] = 1;
    dists[1] = 0;

    while (!q.empty()) {
      auto [cur, curTime] = q.front();
      q.pop();

      int newTime = 0;
      if ((curTime / change) % 2 == 0) {
        newTime = curTime + time;
      } else {
        newTime = curTime + (change - curTime % change) + time;
      }

      for (auto& next : g[cur]) {
        if (visited[next] < 2 && newTime > dists[next]) {
          ++visited[next];
          dists[next] = newTime;

          if (next == n && visited[next] == 2) {
            return dists[next];
          }

          q.push({next, newTime});
        }
      }
    }

    return -1;
  }
};
// 370 ms
// 185.53 MB