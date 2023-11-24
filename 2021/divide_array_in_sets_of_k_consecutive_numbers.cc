class Solution {
 public:
  bool isPossibleDivide(vector<int>& nums, int k) {
    unordered_map<int, int> mp;

    for (auto n : nums) {
      ++mp[n];
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size();) {
      int n = nums[i];

      if (mp[n] <= 0) {
        ++i;
        continue;
      }

      for (int j = 0; j < k; ++j) {
        if (mp[n] <= 0) {
          return false;
        }

        --mp[n];
        n += 1;
      }
    }

    return true;
  }
};
// Runtime: 172 ms, faster than 84.34%
// Memory Usage: 27.6 MB, less than 100.00%

class Solution {
 public:
  bool isPossibleDivide(vector<int>& nums, int k) {
    map<int, int> mp;

    for (auto n : nums) {
      ++mp[n];
    }

    for (auto m : mp) {
      if (m.second > 0) {
        for (int i = k - 1; i >= 0; --i) {
          if ((mp[m.first + i] -= m.second) < 0) {
            return false;
          }
        }
      }
    }

    return true;
  }
};
// Runtime: 204 ms, faster than 60.69%
// Memory Usage: 30.3 MB, less than 100.00%