class Solution {
 public:
  int maxScoreSightseeingPair(vector<int>& values) {
    int ans = 0;
    int curmax = 0;
    int n = values.size();
    for (int i = 0; i < n; ++i) {
      ans = max(ans, curmax + values[i] - i);
      curmax = max(curmax, values[i] + i);
    }

    return ans;
  }
};
// 40 ms
// 43.22 MB