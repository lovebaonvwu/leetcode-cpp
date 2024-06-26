class Solution {
 public:
  int minOperations(vector<int>& nums) {
    int n = nums.size();

    int ans = 0;
    int cur = 0;
    for (int i = 0; i < n; ++i) {
      if (nums[i] + cur % 2 == 1)
        continue;
      ++ans;
      ++cur;
    }

    return ans;
  }
};
// 121 ms
// 154.81 MB