class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    unordered_map<int, int> mp;

    for (auto n : nums) {
      ++mp[n];
    }

    int ans = 0;
    for (auto& m : mp) {
      if (m.second == 1) {
        ans = m.first;
        break;
      }
    }

    return ans;
  }
};
// Runtime: 16 ms, faster than 31.58%
// Memory Usage: 8 MB, less than 100.00%

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ans = 0;

    for (int i = 0; i < 32; ++i) {
      int mask = 1 << i;
      int cnt = 0;

      for (auto n : nums) {
        if (n & mask) {
          ++cnt;
        }
      }

      if (cnt % 3 != 0) {
        ans |= mask;
      }
    }

    return ans;
  }
};
// Runtime: 16 ms, faster than 31.58%
// Memory Usage: 7.6 MB, less than 100.00%