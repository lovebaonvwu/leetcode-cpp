class Solution {
 public:
  int calculateTime(string keyboard, string word) {
    unordered_map<char, int> mp;
    for (int i = 0; i < keyboard.size(); ++i) {
      mp[keyboard[i]] = i;
    }

    int ans = 0, prev = 0;
    for (auto c : word) {
      ans += abs(mp[c] - prev);
      prev = mp[c];
    }

    return ans;
  }
};
// Runtime 24 ms
// Memory 7 MB
// 2022.11.27 at 茗筑美嘉