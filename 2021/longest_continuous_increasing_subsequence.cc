class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (i == 0 || nums[i] > nums[i - 1]) {
        ans = max(ans, ++cnt);
      } else {
        cnt = 1;
      }
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 95.48%
// Memory Usage: 9.4 MB, less than 72.22%

class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    int ans = 1;
    int cnt = ans;

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        ++cnt;
      } else {
        ans = max(ans, cnt);
        cnt = 1;
      }
    }

    return max(ans, cnt);
  }
};
// Runtime: 12 ms, faster than 95.48%
// Memory Usage: 9.3 MB, less than 100.00%