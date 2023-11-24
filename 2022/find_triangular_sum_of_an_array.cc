class Solution {
 public:
  int triangularSum(vector<int>& nums) {
    while (nums.size() > 1) {
      vector<int> tmp;

      for (int i = 0; i < nums.size() - 1; ++i) {
        tmp.push_back((nums[i] + nums[i + 1]) % 10);
      }

      swap(nums, tmp);
    }

    return nums[0];
  }
};
// Runtime: 1031 ms, faster than 8.91%
// Memory Usage: 379.1 MB, less than 18.61%
// 2022.4.7 at 奥盛大厦

class Solution {
 public:
  int triangularSum(vector<int>& nums) {
    int n = nums.size(), k = n;

    while (n - 1 > 0) {
      for (int i = 0; i < k - 1; ++i) {
        nums[i] += nums[i + 1];
        nums[i] %= 10;
      }

      --k;
      --n;
    }

    return nums[0];
  }
};
// Runtime: 264 ms, faster than 89.11%
// Memory Usage: 18.6 MB, less than 73.24%
// 2022.4.7 at 奥盛大厦