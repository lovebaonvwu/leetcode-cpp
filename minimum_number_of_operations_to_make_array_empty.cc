class Solution {
 public:
  int minOperations(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (auto n : nums) {
      ++mp[n];
    }

    int ans = 0;

    for (auto [_, cnt] : mp) {
      if (cnt % 3 == 1) {
        cnt -= 2;
        ans += 1;
      }

      if (cnt < 0) {
        return -1;
      }

      if (cnt % 3 == 2) {
        cnt -= 2;
        ans += 1;
      }

      ans += cnt / 3;
    }

    return ans;
  }
};
// 109ms
// 85.06MB