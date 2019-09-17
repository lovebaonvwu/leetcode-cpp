class Solution {
 public:
  vector<string> uncommonFromSentences(string A, string B) {
    string s = A + ' ' + B + ' ';

    unordered_map<string, int> mp;
    string w;
    for (const char& ch : s) {
      if (isspace(ch)) {
        mp[w]++;

        w = "";

        continue;
      }

      w += ch;
    }

    vector<string> ans;
    for (const auto& m : mp) {
      if (m.second == 1) {
        ans.push_back(m.first);
      }
    }

    return ans;
  }
};  // 0ms