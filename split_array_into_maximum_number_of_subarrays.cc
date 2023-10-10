class Solution {
 public:
  int maxSubarrays(vector<int>& nums) {
    int ans = 0;
    int cur = 0;
    for (auto n : nums) {
      cur = cur == 0 ? n : (cur & n);
      ans += cur == 0;
    }

    return max(1, ans);
  }
};
// 115ms
// 105.08MB