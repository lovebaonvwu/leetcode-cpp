class Solution {
 public:
  int maxDepth(string s) {
    int ans = 0;
    int cnt = 0;

    for (auto c : s) {
      if (c == '(') {
        ++cnt;
      } else if (c == ')') {
        --cnt;
      }

      ans = max(ans, cnt);
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.5 MB, less than 25.00%