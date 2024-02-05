class Solution {
 public:
  int returnToBoundaryCount(vector<int>& nums) {
    int ans = 0;
    int cur = 0;
    for (auto n : nums) {
      cur += n;
      ans += cur == 0;
    }

    return ans;
  }
};
// 4 ms
// 22.28 MB