class Solution {
 public:
  int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
    unordered_map<int, vector<int>> g;
    for (auto& e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }

    vector<int> visited(patience.size());

    queue<int> q;
    q.push(0);

    int ans = 0, sec = 0;

    while (!q.empty()) {
      int cnt = q.size();

      while (cnt-- > 0) {
        auto node = q.front();
        q.pop();

        int p = patience[node];
        int t = 2 * sec;

        if (p > 0) {
          if (p >= t) {
            ans = max(ans, t);
          } else {
            int resend = (t - 1) / p;
            int delay = p * resend;
            ans = max(ans, t + delay);
          }
        }

        for (auto& next : g[node]) {
          if (visited[next]) {
            continue;
          }

          q.push(next);
          visited[next] = true;
        }
      }
      ++sec;
    }

    return ans + 1;
  }
};
// Runtime: 1133 ms, faster than 31.30%
// Memory Usage: 218.5 MB, less than 14.20%
// 2022.5.14 at 茗筑美嘉