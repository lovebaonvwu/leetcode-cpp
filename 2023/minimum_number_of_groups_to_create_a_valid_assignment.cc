class Solution {
 public:
  int minGroupsForValidAssignment(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (auto n : nums)
      ++mp[n];

    int k = nums.size();
    for (auto& [_, v] : mp)
      k = min(k, v);

    int ans = k;
    for (int i = k + 1; i >= 1; --i) {
      int cnt = 0;
      bool valid = true;
      for (auto& [_, v] : mp) {
        int r = v % i;
        int d = v / i;
        if (r == 0) {
          cnt += d;
          continue;
        }

        if (i - r > d + 1) {
          valid = false;
          break;
        }

        cnt += d + 1;
      }

      if (valid) {
        ans = cnt;
        break;
      }
    }

    return ans;
  }
};
// 184ms
// 126.61MB