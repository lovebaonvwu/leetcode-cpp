class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
      while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
        swap(nums[nums[i] - 1], nums[i]);
      }
    }

    for (int i = 0; i < n; ++i) {
      if (nums[i] != i + 1) {
        return i + 1;
      }
    }

    return n + 1;
  }
};  // 4ms

class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    unordered_map<int, int> mp;
    int max = INT_MIN;

    for (int& n : nums) {
      mp[n] = 1;
      if (n > max) {
        max = n;
      }
    }

    if (max < 0) {
      return 1;
    }

    for (int i = 1; i < max; ++i) {
      if (!mp[i]) {
        return i;
      }
    }

    return max + 1;
  }
};  // 4ms