class Solution {
 public:
  int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
    int n = s.size();
    int limit = 1e9 + 7;
    vector<int> visited(26, limit);
    for (int i = 0; i < n; ++i) {
      int cur = max(abs(points[i][0]), abs(points[i][1]));
      if (visited[s[i] - 'a'] > cur) {
        swap(cur, visited[s[i] - 'a']);
      }
      limit = min(limit, cur);
    }

    int ans = 0;
    for (auto v : visited) {
      ans += v < limit;
    }

    return ans;
  }
};
// 198 ms
// 97.71 MB