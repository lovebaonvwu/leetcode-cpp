class Solution {
 public:
  int countWays(vector<vector<int>>& ranges) {
    sort(ranges.begin(), ranges.end());

    vector<int> prev = ranges[0];

    int ans = 2, mod = 1e9 + 7;

    for (int i = 1; i < ranges.size(); ++i) {
      int s = ranges[i][0], e = ranges[i][1];

      if (s <= prev[1]) {
        prev[1] = max(prev[1], e);
      } else {
        ans = (ans * 2) % mod;
        prev = ranges[i];
      }
    }

    return ans;
  }
};
// Runtime 378 ms
// Memory 72.7 MB