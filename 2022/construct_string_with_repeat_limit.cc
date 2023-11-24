class Solution {
 public:
  string repeatLimitedString(string s, int repeatLimit) {
    sort(s.rbegin(), s.rend());

    for (int i = 1, cnt = 1; i < s.size(); ++i) {
      if (s[i] == s[i - 1]) {
        ++cnt;
      } else {
        cnt = 1;
      }

      if (cnt > repeatLimit) {
        int j = i;
        while (s[j] == s[i]) {
          ++j;
        }

        if (j == s.size()) {
          return s.substr(0, i);
        }

        swap(s[i], s[j]);
      }
    }

    return s;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  string repeatLimitedString(string s, int repeatLimit) {
    int cnt[26] = {0};

    for (auto c : s) {
      ++cnt[c - 'a'];
    }

    string ans;
    int prevsize = -1;

    int k = 0;
    while (ans.size() < s.size()) {
      for (int i = 25; i >= 0; --i) {
        if (cnt[i] == 0) {
          continue;
        }

        if ((i + 'a') == ans.back() && k == repeatLimit) {
          continue;
        }

        k = (i + 'a') == ans.back() ? k + 1 : 1;

        ans.push_back((i + 'a'));
        --cnt[i];
        break;
      }

      if (prevsize == ans.size()) {
        break;
      }

      prevsize = ans.size();
    }

    return ans;
  }
};
// Runtime: 84 ms, faster than 88.22%
// Memory Usage: 24.6 MB, less than 73.16%
// 2022.2.25 at 奥盛大厦