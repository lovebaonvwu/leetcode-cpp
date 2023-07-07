class Solution {
 public:
  int equalSubstring(string s, string t, int maxCost) {
    int ans = 0;
    for (int i = 0, j = 0, cost = 0; j < s.size(); ++j) {
      cost += abs(s[j] - t[j]);
      while (cost > maxCost) {
        cost -= abs(s[i] - t[i]);
        ++i;
      }

      ans = max(ans, j - i + 1);
    }

    return ans;
  }
};
// Runtime 7 ms
// Memory 7.6 MB