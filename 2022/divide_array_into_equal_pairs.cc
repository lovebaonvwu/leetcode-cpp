class Solution {
 public:
  bool divideArray(vector<int>& nums) {
    int cnt[501] = {0};

    for (auto n : nums) {
      ++cnt[n];
    }

    for (int i = 0; i < 501; ++i) {
      if (cnt[i] & 1) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 19 ms, faster than 46.15%
// Memory Usage: 12.9 MB, less than 53.85%
// 2022.3.20 at 茗筑美嘉