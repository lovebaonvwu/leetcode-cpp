class Solution {
 public:
  int maximumXOR(vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 0, bit_or<int>());
  }
};
// Runtime: 143 ms, faster than 50.00%
// Memory Usage: 48.1 MB, less than 50.00%
// 2022.6.26 at 茗筑美嘉