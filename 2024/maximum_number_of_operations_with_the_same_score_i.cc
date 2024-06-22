class Solution {
 public:
  int maxOperations(vector<int>& nums) {
    int ans = 1;
    int prev = nums[0] + nums[1];

    for (int i = 2; i < nums.size() - 1; i += 2) {
      if (nums[i] + nums[i + 1] != prev)
        break;
      ++ans;
    }

    return ans;
  }
};
// 0 ms
// 20.03 MB
