class Solution {
 public:
  bool kLengthApart(vector<int>& nums, int k) {
    int slow = 0;

    while (slow < nums.size() && nums[slow] == 0) {
      ++slow;
    }

    for (int fast = slow + 1; fast < nums.size(); ++fast) {
      if (!nums[fast]) {
        continue;
      }

      if (fast - slow - 1 < k) {
        return false;
      }

      slow = fast;
    }

    return true;
  }
};
// Runtime: 148 ms, faster than 84.68%
// Memory Usage: 57.7 MB, less than 100.00%

class Solution {
 public:
  bool kLengthApart(vector<int>& nums, int k) {
    int i = -1;

    for (int j = 0; j < nums.size(); ++j) {
      if (nums[j]) {
        if (i != -1 && j - i - 1 < k) {
          return false;
        }

        i = j;
      }
    }

    return true;
  }
};
// Runtime: 156 ms, faster than 70.92%
// Memory Usage: 57.7 MB, less than 100.00%