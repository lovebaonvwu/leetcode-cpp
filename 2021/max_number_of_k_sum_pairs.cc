class Solution {
 public:
  int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> mp;

    for (auto n : nums) {
      ++mp[n];
    }

    int ans = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != k - nums[i]) {
        if (mp[nums[i]] > 0 && mp[k - nums[i]] > 0) {
          --mp[nums[i]];
          --mp[k - nums[i]];
          ++ans;
        }
      } else if (nums[i] == k - nums[i]) {
        if (mp[nums[i]] > 1) {
          mp[nums[i]] -= 2;
          ++ans;
        }
      }
    }

    return ans;
  }
};
// Runtime: 392 ms, faster than 33.33%
// Memory Usage: 73.3 MB, less than 33.33%

class Solution {
 public:
  int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> mp;

    for (auto n : nums) {
      ++mp[n];
    }

    int ans = 0;

    for (int i = 0; i < nums.size(); ++i) {
      int cnt = mp[nums[i]];
      if (nums[i] == k - nums[i]) {
        mp[nums[i]] -= cnt;
        ans += cnt / 2;
      } else if (mp.count(k - nums[i])) {
        cnt = min(cnt, mp[k - nums[i]]);
        mp[nums[i]] -= cnt;
        mp[k - nums[i]] -= cnt;
        ans += cnt;
      }
    }

    return ans;
  }
};
// Runtime: 384 ms, faster than 33.33%
// Memory Usage: 68.1 MB, less than 66.67%