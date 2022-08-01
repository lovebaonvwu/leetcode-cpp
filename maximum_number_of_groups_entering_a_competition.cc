class Solution {
 public:
  int maximumGroups(vector<int>& grades) {
    int total = 0;
    int cnt = 1;

    int ans = 0;
    while (total <= grades.size()) {
      total += cnt++;
      ans++;
    }

    return ans -= total > grades.size();
  }
};
// Runtime: 102 ms, faster than 100.00%
// Memory Usage: 56.6 MB, less than 100.00%
// 2022.8.1 at 奥盛大厦

class Solution {
 public:
  int maximumGroups(vector<int>& grades) {
    int lo = 1, hi = 1000, n = grades.size();

    while (lo < hi) {
      int k = (lo + hi + 1) / 2;

      if ((1 + k) * k / 2 > n) {
        hi = k - 1;
      } else {
        lo = k;
      }
    }

    return lo;
  }
};
// Runtime: 128 ms, faster than 100.00%
// Memory Usage: 56.5 MB, less than 100.00%
// 2022.8.1 at 奥盛大厦