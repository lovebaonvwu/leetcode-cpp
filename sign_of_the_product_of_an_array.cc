class Solution {
 public:
  int arraySign(vector<int>& nums) {
    int countOfNegative = 0;

    for (auto n : nums) {
      if (n < 0) {
        ++countOfNegative;
      } else if (n == 0) {
        return 0;
      }
    }

    return countOfNegative % 2 == 0 ? 1 : -1;
  }
};
// Runtime: 8 ms, faster than 62.64%
// Memory Usage: 10.1 MB, less than 93.21%