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

class Solution {
  bool valid(const vector<int>& ss, const vector<int>& tt) {
    for (int i = 0; i < 128; ++i) {
      if (ss[i] < tt[i]) {
        return false;
      }
    }

    return true;
  }

 public:
  string minWindow(string s, string t) {
    vector<int> tt(128);
    for (auto c : t) {
      ++tt[c];
    }

    vector<int> ss(128);
    int curlen = INT_MAX;
    int curindex = -1;
    for (int i = 0, j = 0; i < s.size(); ++i) {
      ++ss[s[i]];

      while (valid(ss, tt)) {
        if ((i - j + 1) < curlen) {
          curindex = j;
          curlen = i - j + 1;
        }

        --ss[s[j]];
        ++j;
      }
    }

    return curindex == -1 ? "" : s.substr(curindex, curlen);
  }
};