class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string, int> cnt;
    for (auto& w : words) {
      ++cnt[w];
    }

    int n = s.size(), len = words[0].size();

    vector<int> ans;
    for (int i = 0; i < n - len * words.size() + 1; ++i) {
      unordered_map<string, int> seen;

      int j = 0;
      for (; j < words.size(); ++j) {
        string w = s.substr(i + len * j, len);
        if (cnt.find(w) == cnt.end()) {
          break;
        }

        ++seen[w];
        if (seen[w] > cnt[w]) {
          break;
        }
      }

      if (j == words.size()) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// Runtime: 586 ms, faster than 40.63%
// Memory Usage: 24.6 MB, less than 66.39%
// 2022.8.13 at 茗筑美嘉