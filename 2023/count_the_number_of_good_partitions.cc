class Solution {
 public:
  int numberOfGoodPartitions(vector<int>& nums) {
    unordered_map<int, int> last;
    for (int i = 0; i < nums.size(); ++i) {
      last[nums[i]] = i;
    }

    int ans = 1;
    int mod = 1e9 + 7;
    for (int i = 0, j = 0; i < nums.size(); ++i) {
      if (i > j) {
        ans = (2 * ans) % mod;
      }

      j = max(j, last[nums[i]]);
    }

    return ans;
  }
};
// 220ms
// 134.60MB