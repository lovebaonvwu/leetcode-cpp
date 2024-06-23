class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    int ans = 0;
    for (auto n : nums) {
      int reminder = n % 3;
      ans += min(3 - reminder, reminder - 0);
    }

    return ans;
  }
};
// 8 ms
// 22.17 MB
