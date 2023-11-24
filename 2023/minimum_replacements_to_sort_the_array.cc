class Solution {
 public:
  long long minimumReplacement(vector<int>& nums) {
    long long ans = 0;
    int n = nums.size();
    for (int i = n - 2; i >= 0; --i) {
      if (nums[i] > nums[i + 1]) {
        if (nums[i] % nums[i + 1] == 0) {
          ans += nums[i] / nums[i + 1] - 1;
          nums[i] = nums[i + 1];
        } else {
          int piece = (nums[i] + nums[i + 1] - 1) / nums[i + 1];
          ans += piece - 1;
          nums[i] = nums[i] / piece;
        }
      }
    }

    return ans;
  }
};
// 88ms
// 54.73MB