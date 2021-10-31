class Solution {
 public:
  int smallestEqual(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      if (i % 10 == nums[i]) {
        return i;
      }
    }

    return -1;
  }
};
// Runtime: 16 ms, faster than 36.36%
// Memory Usage: 22.1 MB, less than 27.27%
// 2021.10.31 at 茗筑美嘉