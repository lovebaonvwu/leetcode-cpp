class Solution {
 public:
  bool isPossible(vector<int>& nums) {
    unordered_map<int, int> left, end;

    for (auto n : nums) {
      ++left[n];
    }

    for (auto n : nums) {
      if (left[n] == 0) {
        continue;
      }

      --left[n];
      if (end[n - 1] > 0) {
        --end[n - 1];
        ++end[n];
      } else if (left[n + 1] > 0 && left[n + 2] > 0) {
        --left[n + 1];
        --left[n + 2];
        ++end[n + 2];
      } else {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 145 ms, faster than 56.44%
// Memory Usage: 58.2 MB, less than 77.13%
// 2022.6.20 at 奥盛大厦