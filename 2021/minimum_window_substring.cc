class Solution {
 public:
  string minWindow(string s, string t) {
    vector<int> table(128);

    int cnt = t.size();

    for (auto c : t) {
      ++table[c];
    }

    int l = 0, r = 0, start = 0, n = s.size();
    int minlen = INT_MAX;

    while (r <= n && l < n) {
      if (cnt > 0) {
        if (r == n) {
          break;
        }

        --table[s[r]];

        if (table[s[r]] >= 0) {
          --cnt;
        }

        ++r;
      } else {
        if (r - l < minlen) {
          minlen = r - l;
          start = l;
        }

        ++table[s[l]];

        if (table[s[l]] > 0) {
          ++cnt;
        }

        ++l;
      }
    }

    return minlen == INT_MAX ? "" : s.substr(start, minlen);
  }
};
// Runtime: 8 ms, faster than 88.32%
// Memory Usage: 7.8 MB, less than 65.85%
// 2021.8.15 at 茗筑美嘉