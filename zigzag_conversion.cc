class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 0) {
      return s;
    }

    vector<vector<char>> v(numRows, vector<char>(s.size(), ' '));

    int cnt = 0;

    int j = 0;
    while (cnt < s.size()) {
      int i = 0;

      for (; i < numRows; ++i) {
        if (cnt < s.size()) {
          v[i][j] = s[cnt++];
        }
      }

      if (cnt == s.size()) {
        break;
      }

      for (i = numRows - 2; i >= 1; --i) {
        if (cnt < s.size()) {
          ++j;
          v[i][j] = s[cnt++];
        }
      }
      ++j;

      if (cnt == s.size()) {
        break;
      }
    }

    string ans = "";

    for (auto& row : v) {
      for (auto& ch : row) {
        if (ch != ' ') {
          ans += ch;
        }
      }
    }

    return ans;
  }
};  // 56ms