class Solution {
 public:
  int maximizeSum(vector<int>& nums, int k) {
    int a = *max_element(nums.begin(), nums.end());

    return (a + a + k - 1) * k / 2;
  }
};
// Runtime 57 ms
// Memory 70.6 MB