class Solution {
 public:
  vector<int> numberOfPairs(vector<int>& nums) {
    int cnt[101] = {0};

    for (auto n : nums) {
      ++cnt[n];
    }

    vector<int> ans(2);

    for (int i = 0; i < 101; ++i) {
      ans[0] += cnt[i] / 2;
      ans[1] += cnt[i] % 2;
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 62.77%
// Memory Usage: 9.2 MB, less than 84.72%
// 2022.7.30 at 茗筑美嘉