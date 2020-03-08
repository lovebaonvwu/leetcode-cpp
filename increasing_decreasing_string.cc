class Solution {
 public:
  string sortString(string s) {
    int chs[26] = {0};

    int cnt = 0;
    for (auto ch : s) {
      ++chs[ch - 'a'];
      ++cnt;
    }

    string ans;
    while (cnt > 0) {
      for (int i = 0; i < 26; ++i) {
        if (chs[i] > 0) {
          ans.append(1, i + 'a');
          --chs[i];
          --cnt;
        }
      }

      for (int i = 25; i >= 0; --i) {
        if (chs[i] > 0) {
          ans.append(1, i + 'a');
          --chs[i];
          --cnt;
        }
      }
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 50.00%
// Memory Usage: 8.9 MB, less than 100.00%

class Solution {
 public:
  string sortString(string s) {
    int chs[26] = {0};

    for (auto ch : s) {
      ++chs[ch - 'a'];
    }

    string ans;
    while (s.size() != ans.size()) {
      for (int i = 0; i < 26; ++i) {
        if (chs[i] > 0) {
          ans.append(1, i + 'a');
          --chs[i];
        }
      }

      for (int i = 25; i >= 0; --i) {
        if (chs[i] > 0) {
          ans.append(1, i + 'a');
          --chs[i];
        }
      }
    }

    return ans;
  }
};
// Runtime: 16 ms, faster than 33.33%
// Memory Usage: 8.9 MB, less than 100.00%