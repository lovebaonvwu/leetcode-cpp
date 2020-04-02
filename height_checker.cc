class Solution {
 public:
  int heightChecker(vector<int>& heights) {
    vector<int> cp(heights);

    sort(cp.begin(), cp.end());

    int ans = 0;

    for (int i = 0; i < cp.size(); ++i) {
      ans += cp[i] != heights[i];
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.4 MB, less than 100.00%