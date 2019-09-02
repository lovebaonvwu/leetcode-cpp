class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows <= 1) {
      return s;
    }

    string ans = "";

    for (int i = 0; i < s.size(); i += 2 * (numRows - 1)) {
      ans += s[i];
    }

    for (int i = 1; i < numRows - 1; ++i) {
      for (int j = i; j < s.size(); j += 2 * (numRows - 1)) {
        ans += s[j];

        int index = j + 2 * (numRows - i - 1);
        if (index < s.size()) {
          ans += s[index];
        }
      }
    }

    for (int i = numRows - 1; i < s.size(); i += 2 * (numRows - 1)) {
      ans += s[i];
    }

    return ans;
  }
};  // 8ms

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