class Solution {
 public:
  string sortSentence(string s) {
    vector<string> words(9);

    stringstream ss(s);

    string t;

    while (ss >> t) {
      words[t[t.size() - 1] - '0' - 1] = t.substr(0, t.size() - 1);
    }

    string ans;

    for (auto& w : words) {
      if (!w.empty()) {
        ans += w + ' ';
      }
    }

    return ans.substr(0, ans.size() - 1);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 90.79%
// 2021.8.11 at 奥盛大厦