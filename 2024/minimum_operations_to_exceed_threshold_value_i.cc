class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    int ans = 0;
    for (auto n : nums) {
      if (n < k) {
        ++ans;
      }
    }

    return ans;
  }
};
// 7 ms
// 23.70 MB