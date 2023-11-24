class Solution {
 public:
  int maxNonOverlapping(vector<int>& nums, int target) {
    vector<pair<int, int>> intervals;

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i, sum = 0; j < nums.size(); ++j) {
        sum += nums[j];

        if (sum == target) {
          intervals.push_back({i, j});
        }
      }
    }

    if (intervals.empty()) {
      return 0;
    }

    sort(intervals.begin(), intervals.end(),
         [](auto& a, auto& b) { return a.second < b.second; });

    int ans = 1;
    int prev = intervals[0].second;

    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i].first > prev) {
        ++ans;
        prev = intervals[i].second;
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int maxNonOverlapping(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    mp[0] = -1;

    int ans = 0;
    for (int i = 0, sum = 0, right_bound = -1; i < nums.size(); ++i) {
      sum += nums[i];

      if (mp.count(sum - target)) {
        int left_bound = mp[sum - target];

        if (left_bound >= right_bound) {
          ++ans;
          right_bound = i;
        }
      }

      mp[sum] = i;
    }

    return ans;
  }
};
// Runtime: 680 ms, faster than 32.30%
// Memory Usage: 82.8 MB, less than 74.73%