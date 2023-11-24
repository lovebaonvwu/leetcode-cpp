class Solution {
 public:
  int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    unordered_map<int, vector<int>> g;
    vector<int> ind(n);

    for (auto& r : relations) {
      int x = r[0] - 1;
      int y = r[1] - 1;
      g[x].push_back(y);
      ++ind[y];
    }

    queue<int> q;
    vector<int> maxtime(n);

    for (int i = 0; i < n; ++i) {
      if (ind[i] == 0) {
        q.push(i);
        maxtime[i] = time[i];
      }
    }

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (auto next : g[cur]) {
        maxtime[next] = max(maxtime[next], maxtime[cur] + time[next]);
        --ind[next];
        if (ind[next] == 0) {
          q.push(next);
        }
      }
    }

    return *max_element(maxtime.begin(), maxtime.end());
  }
};
// 349ms
// 144.64MB