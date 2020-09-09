class Solution {
 public:
  vector<string> removeComments(vector<string>& source) {
    vector<string> ans;

    bool block = false;
    bool hasPrev = false;

    for (auto& s : source) {
      string line;

      if (block && hasPrev && !ans.empty()) {
        line = ans.back();
        ans.pop_back();
      }

      for (int i = 0; i < s.size(); ++i) {
        if (block && s[i] == '*' && i + 1 < s.size() && s[i + 1] == '/') {
          block = false;
          ++i;
          continue;
        }

        if (block) {
          continue;
        }

        if (s[i] == '/' && i + 1 < s.size() && s[i + 1] == '*') {
          if (!line.empty()) {
            hasPrev = true;
          } else {
            hasPrev = false;
          }

          block = true;
          ++i;
          continue;
        }

        if (s[i] == '/' && i + 1 < s.size() && s[i + 1] == '/') {
          break;
        }

        line += s[i];
      }

      if (!line.empty()) {
        ans.push_back(line);
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.7 MB, less than 90.23%