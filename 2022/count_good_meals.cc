class Solution {
 public:
  int countPairs(vector<int>& deliciousness) {
    unordered_map<int, int> mp;

    long long ans = 0;
    int mod = 1e9 + 7;

    for (auto x : deliciousness) {
      for (int i = 1; i <= (1 << 21); i *= 2) {
        if (mp.find(i - x) != mp.end()) {
          ans = (ans + mp[i - x]) % mod;
        }
      }
      mp[x] += 1;
    }

    return ans;
  }
};
// Runtime: 669 ms, faster than 45.56%
// Memory Usage: 57.9 MB, less than 68.89%
// 2022.5.4 at 茗筑美嘉