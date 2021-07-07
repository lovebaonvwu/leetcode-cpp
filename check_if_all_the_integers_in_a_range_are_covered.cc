class Solution {
 public:
  bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    vector<int> range(52);

    for (auto r : ranges) {
      ++range[r[0]];
      --range[r[1] + 1];
    }

    for (int i = 1; i < range.size(); ++i) {
      range[i] += range[i - 1];
    }

    for (int i = left; i <= right; ++i) {
      if (range[i] <= 0) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 4 ms, faster than 85.94%
// Memory Usage: 9 MB, less than 18.33%
// 2021.7.7 at 奥盛大厦