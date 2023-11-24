class Solution {
 public:
  int longestStrChain(vector<string>& words) {
    unordered_map<string, int> mp;

    for (auto& w : words) {
      mp[w] = 1;
    }

    sort(words.begin(), words.end(),
         [](auto& a, auto& b) { return a.size() < b.size(); });

    int ans = 0;

    for (auto& w : words) {
      for (int i = 0; i < w.size(); ++i) {
        auto s = w.substr(0, i) + w.substr(i + 1);
        mp[w] = max(mp[w], mp[s] + 1);
      }

      ans = max(ans, mp[w]);
    }

    return ans;
  }
};
// Runtime: 136 ms, faster than 34.58%
// Memory Usage: 50.6 MB, less than 17.50%