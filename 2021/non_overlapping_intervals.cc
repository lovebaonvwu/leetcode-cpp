class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();

    if (n == 0) {
      return 0;
    }

    sort(intervals.begin(), intervals.end());

    vector<int> dp(n);
    dp[0] = 1;

    for (int i = 1; i < n; ++i) {
      int max_cnt = 0;
      for (int j = i - 1; j >= 0; --j) {
        if (intervals[i][0] >= intervals[j][1]) {
          max_cnt = max(max_cnt, dp[j]);
        }
      }

      dp[i] = max_cnt + 1;
    }

    return n - dp[n - 1];
  }
};
// Runtime: 724 ms, faster than 5.12%
// Memory Usage: 10.4 MB, less than 56.69%

class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();

    if (n == 0) {
      return 0;
    }

    sort(intervals.begin(), intervals.end(),
         [](auto& a, auto& b) { return a[1] < b[1]; });

    int prev_end = intervals[0][1];

    int ans = 0;
    for (int i = 1; i < n; ++i) {
      if (intervals[i][0] < prev_end) {
        ++ans;
      } else {
        prev_end = intervals[i][1];
      }
    }

    return ans;
  }
};
// Runtime: 28 ms, faster than 94.77%
// Memory Usage: 10.3 MB, less than 70.03%