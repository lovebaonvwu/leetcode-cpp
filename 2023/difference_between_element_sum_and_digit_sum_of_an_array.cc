class Solution {
 public:
  int differenceOfSum(vector<int>& nums) {
    int e_sum = accumulate(begin(nums), end(nums), 0);
    int d_sum = 0;
    for (auto n : nums) {
      while (n > 0) {
        d_sum += n % 10;
        n /= 10;
      }
    }

    return abs(e_sum - d_sum);
  }
};
// 12ms
// 15.90MB