class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
      return {};
    }

    sort(intervals.begin(), intervals.end(),
         [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

    vector<vector<int>> ans;

    ans.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i) {
      if (ans.back()[1] < intervals[i][0]) {
        ans.push_back(intervals[i]);
      } else {
        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
      }
    }

    return ans;
  }
};
// Runtime: 20 ms, faster than 72.27%
// Memory Usage: 12.2 MB, less than 100.00%

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
      return {};
    }

    sort(intervals.begin(), intervals.end(),
         [](vector<int> a, vector<int> b) { return a[0] < b[0]; });

    vector<vector<int>> ans;

    ans.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i) {
      if (ans.back()[1] < intervals[i][0]) {
        ans.push_back(intervals[i]);
      } else {
        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
      }
    }

    return ans;
  }
};
// Runtime: 72 ms, faster than 19.36%
// Memory Usage: 26.6 MB, less than 9.30%