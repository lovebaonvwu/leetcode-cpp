class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    int ans = 0;

    unordered_map<int, int> mp;

    for (const auto& n : nums) {
      ++mp[n];
    }

    for (const auto& p : mp) {
      if (k > 0 && mp.count(p.first - k)) {
        ++ans;
      } else if (k == 0 && p.second > 1) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 36 ms, faster than 64.73%
// Memory Usage: 14.9 MB, less than 18.18%

class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    int ans = 0;

    if (k < 0) {
      return ans;
    }

    unordered_map<int, int> mp;

    for (const auto& n : nums) {
      ++mp[n];
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size();) {
      if (k == 0) {
        if (mp[nums[i]] > 1) {
          ++ans;
        }
      } else if (mp[nums[i] - k]) {
        ++ans;
      }

      ++i;
      while (i < nums.size() && nums[i - 1] == nums[i]) {
        ++i;
      }
    }

    return ans;
  }
};
// Runtime: 40 ms, faster than 47.90%
// Memory Usage: 12.8 MB, less than 36.36%

class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    int ans = 0;

    unordered_set<int> st(nums.begin(), nums.end());
    unordered_map<int, int> mp;

    for (const auto& n : nums) {
      ++mp[n];
    }

    for (const auto& s : st) {
      if (k > 0 && mp[s - k]) {
        ++ans;
      } else if (k == 0 && mp[s] > 1) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 56 ms, faster than 18.00%
// Memory Usage: 19.5 MB, less than 9.09%

class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    int ans = 0;

    if (nums.empty()) {
      return ans;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 1;) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if (nums[j] - nums[i] == k) {
          ++ans;
          break;
        }
      }

      ++i;

      while (i < nums.size() && nums[i] == nums[i - 1]) {
        ++i;
      }
    }

    return ans;
  }
};
// Runtime: 460 ms, faster than 7.63%
// Memory Usage: 9.7 MB, less than 100.00%