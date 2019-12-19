class Solution {
 public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
      return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    });

    int ans = 1;

    int rb = intervals[0][1];

    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][1] > rb) {
        ++ans;
      }

      rb = max(rb, intervals[i][1]);
    }

    return ans;
  }
};
// Runtime: 88 ms, faster than 22.75%
// Memory Usage: 29 MB, less than 100.00%

class Solution {
 public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    vector<int> ans(intervals.size(), 1);

    for (int i = 0; i < intervals.size() - 1; ++i) {
      for (int j = i + 1; j < intervals.size(); ++j) {
        if (intervals[i][0] <= intervals[j][0] &&
            intervals[i][1] >= intervals[j][1]) {
          ans[j] = 0;
        } else if (intervals[j][0] <= intervals[i][0] &&
                   intervals[j][1] >= intervals[i][1]) {
          ans[i] = 0;
        }
      }
    }

    return count_if(ans.begin(), ans.end(), [](int n) { return n == 1; });
  }
};
// Runtime: 96 ms, faster than 17.90%
// Memory Usage: 11.6 MB, less than 100.00%