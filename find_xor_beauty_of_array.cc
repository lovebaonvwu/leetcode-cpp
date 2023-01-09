class Solution {
 public:
  int xorBeauty(vector<int>& nums) {
    int ans = 0;
    for (auto n : nums) {
      ans ^= n;
    }

    return ans;
  }
};
// Runtime 81 ms
// Memory 39.9 MB
// 2023.1.9 at 奥盛大厦