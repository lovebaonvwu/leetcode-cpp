class Solution {
 public:
  int minImpossibleOR(vector<int>& nums) {
    unordered_set<int> num(nums.begin(), nums.end());

    int ans = 1;
    while (num.count(ans)) {
      ans <<= 1;
    }

    return ans;
  }
};
// Runtime 216 ms
// Memory 68.2 MB
// 2023.2.20 at 奥盛大厦