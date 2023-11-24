class Solution {
 public:
  int findLHS(vector<int>& nums) {
    unordered_map<int, int> mp;

    for (int n : nums) {
      ++mp[n];
    }

    int ans = 0;
    for (int i = 0; i < nums.size(); ++i) {
      int low = mp[nums[i] - 1];
      int high = mp[nums[i] + 1];

      if (!low && !high) {
        continue;
      }

      ans = max(ans, max(low, high) + mp[nums[i]]);
    }

    return ans;
  }
};
// Runtime: 220 ms, faster than 14.97%
// Memory Usage: 28.9 MB, less than 33.33%

class Solution {
 public:
  int findLHS(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int ans = 0;
    for (int i = 0, cnt1 = 0, cnt2 = 0; i < nums.size(); ++i) {
      if (i == 0 || nums[i] == nums[i - 1]) {
        ++cnt1;
      } else if (nums[i] - 1 == nums[i - 1]) {
        cnt2 = cnt1;
        cnt1 = 1;
      } else {
        cnt2 = 0;
        cnt1 = 1;
      }

      if (cnt2 > 0 && cnt1 > 0) {
        ans = max(ans, cnt1 + cnt2);
      }
    }

    return ans;
  }
};
// Runtime: 116 ms, faster than 78.38%
// Memory Usage: 9.1 MB, less than 100.00%