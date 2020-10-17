class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    vector<string> ans;

    if (s.size() < 10) {
      return ans;
    }

    unordered_map<string, int> cnt;

    for (int i = 0; i < s.size() - 9; ++i) {
      string sub = s.substr(i, 10);

      if (cnt[sub] == 1) {
        ans.push_back(sub);
      }

      ++cnt[sub];
    }

    return ans;
  }
};
// Runtime: 84 ms, faster than 73.74%
// Memory Usage: 23.6 MB, less than 13.42%