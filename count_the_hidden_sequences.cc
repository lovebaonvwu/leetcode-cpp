class Solution {
 public:
  int numberOfArrays(vector<int>& differences, int lower, int upper) {
    long long hi = INT_MIN, lo = INT_MAX, cur = 0;

    for (auto n : differences) {
      cur += n;

      lo = min(lo, cur);
      hi = max(hi, cur);
    }

    int ans = 0;
    for (int i = lower; i <= upper; ++i) {
      if (i + lo >= lower && i + hi <= upper) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 292 ms, faster than 49.94%
// Memory Usage: 106.6 MB, less than 69.04%
// 2022.1.25 at 奥盛大厦