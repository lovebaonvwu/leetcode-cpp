class Solution {
 public:
  vector<int> constructArray(int n, int k) {
    vector<int> ans;

    int lo = 1, hi = k + 1;

    while (lo < hi) {
      ans.push_back(lo++);
      ans.push_back(hi--);
    }

    if (lo == hi) {
      ans.push_back(lo);
    }

    for (int i = k + 2; i <= n; ++i) {
      ans.push_back(i);
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 61.34%
// Memory Usage: 7.7 MB, less than 52.10%