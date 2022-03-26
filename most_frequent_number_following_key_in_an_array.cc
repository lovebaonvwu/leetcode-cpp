class Solution {
 public:
  int mostFrequent(vector<int>& nums, int key) {
    vector<int> cnt(1001);

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] == key) {
        ++cnt[nums[i]];
      }
    }

    int ans = 0;
    for (int i = 0, maxCnt = 0; i < 1001; ++i) {
      if (cnt[i] > maxCnt) {
        ans = i;
        maxCnt = cnt[i];
      }
    }

    return ans;
  }
};
// Runtime: 11 ms, faster than 80.47%
// Memory Usage: 13.1 MB, less than 8.30%
// 2022.3.26 at 茗筑美嘉