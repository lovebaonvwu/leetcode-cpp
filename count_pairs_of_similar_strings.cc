class Solution {
 public:
  int similarPairs(vector<string>& words) {
    unordered_map<int, int> mp;
    int ans = 0;
    for (auto& w : words) {
      int pattern = 0;
      for (int i = 0; i < w.size(); ++i) {
        pattern |= 1 << (w[i] - 'a');
      }

      ans += mp[pattern];
      ++mp[pattern];
    }

    return ans;
  }
};
// Runtime 18 ms
// Memory 12.9 MB
// 2022.12.31 at 茗筑美嘉