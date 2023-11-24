class Solution {
 public:
  int minCost(string s, vector<int>& cost) {
    int ans = 0;

    for (int i = 0; i < s.size() - 1; ++i) {
      if (s[i] == s[i + 1]) {
        if (cost[i] < cost[i + 1]) {
          ans += cost[i];
        } else {
          ans += cost[i + 1];
          cost[i + 1] = cost[i];
        }
      }
    }

    return ans;
  }
};
// Runtime: 364 ms, faster than 94.95%
// Memory Usage: 95.5 MB, less than 87.53%