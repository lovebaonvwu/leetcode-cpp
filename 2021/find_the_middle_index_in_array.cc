class Solution {
 public:
  int findMiddleIndex(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    for (int i = 0, tmp = 0; i < nums.size(); ++i) {
      sum -= nums[i];

      if (tmp == sum) {
        return i;
      }

      tmp += nums[i];
    }

    return -1;
  }
};
// Runtime: 8 ms, faster than 32.50%
// Memory Usage: 12.4 MB, less than 72.45%
// 2021.11.16 at 济南市中心医院