class Solution {
 public:
  vector<string> cellsInRange(string s) {
    vector<string> ans;

    for (char i = s[0]; i <= s[3]; ++i) {
      for (char j = s[1]; j <= s[4]; ++j) {
        ans.push_back(string(1, i));
        ans.back().push_back(j);
      }
    }

    return ans;
  }
};
// Runtime: 9 ms
// Memory Usage : 7.8 MB
// 2022.3.12 at 茗筑美嘉

class Solution {
 public:
  vector<string> cellsInRange(string s) {
    vector<string> ans;

    for (char i = s[0]; i <= s[3]; ++i) {
      for (char j = s[1]; j <= s[4]; ++j) {
        ans.push_back({i, j});
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 64.29%
// Memory Usage: 7.8 MB, less than 19.41%
// 2022.3.12 at 茗筑美嘉