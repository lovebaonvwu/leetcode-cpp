class Solution {
 public:
  int maximumDetonation(vector<vector<int>>& bombs) {
    unordered_map<int, vector<int>> mp;

    int n = bombs.size();
    for (int i = 0; i < n; ++i) {
      long long ax = bombs[i][0], ay = bombs[i][1], r = bombs[i][2];
      for (int j = 0; j < n; ++j) {
        if (i == j) {
          continue;
        }

        int bx = bombs[j][0], by = bombs[j][1];

        if ((ax - bx) * (ax - bx) + (ay - by) * (ay - by) <= r * r) {
          mp[i].push_back(j);
        }
      }
    }

    int ans = 0;

    for (int k = 0; k < n; ++k) {
      queue<int> q;
      q.push(k);

      unordered_set<int> visited;
      visited.insert(k);

      int cur = 0;
      while (!q.empty()) {
        int cnt = q.size();

        cur += cnt;
        while (cnt-- > 0) {
          int a = q.front();
          q.pop();

          for (auto& b : mp[a]) {
            if (visited.find(b) == visited.end()) {
              q.push(b);

              visited.insert(b);
            }
          }
        }
      }

      ans = max(ans, cur);
    }

    return ans;
  }
};
// Runtime: 445 ms, faster than 20.93%
// Memory Usage: 48.5 MB, less than 13.07%
// 2021.12.17 at 奥盛大厦