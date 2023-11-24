class Solution {
 public:
  int maxCount(int m, int n, vector<vector<int>>& ops) {
    for (auto& op : ops) {
      m = min(m, op[0]);
      n = min(n, op[1]);
    }

    return m * n;
  }
};
// Runtime: 16 ms, faster than 60.74%
// Memory Usage: 11.2 MB, less than 100.00%