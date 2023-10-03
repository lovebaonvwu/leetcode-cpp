class Solution {
 public:
  long long maximumTripletValue(vector<int>& nums) {
    long long ans = 0;
    long long prev_max = nums[0];
    long long cur_max = 0;
    for (long long n : nums) {
      ans = max(ans, cur_max * n);
      cur_max = max(cur_max, prev_max - n);
      prev_max = max(prev_max, n);
    }

    return ans;
  }
};
// 108ms
// 86.56MB