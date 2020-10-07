class Solution {
 public:
  int specialArray(vector<int>& nums) {
    for (int ans = nums.size(); ans >= 1; --ans) {
      int cnt = 0;
      for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] >= ans) {
          ++cnt;
        }
      }

      if (cnt == ans) {
        return ans;
      }
    }

    return -1;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.6 MB, less than 49.60%

class Solution {
 public:
  int specialArray(vector<int>& nums) {
    vector<int> cnt(101);

    for (auto n : nums) {
      ++cnt[n > 100 ? 100 : n];
    }

    if (cnt[100] == 100) {
      return 100;
    }

    for (int i = 99; i >= 0; --i) {
      cnt[i] = cnt[i] + cnt[i + 1];

      if (cnt[i] == i) {
        return i;
      }
    }

    return -1;
  }
};
// Runtime: 4 ms, faster than 86.49%
// Memory Usage: 8.6 MB, less than 43.88%