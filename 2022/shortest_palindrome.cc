class Solution {
  bool isPalindrome(const string& s) {
    int i = 0, j = s.size() - 1;

    while (i < j) {
      if (s[i] != s[j]) {
        break;
      }

      ++i, --j;
    }

    return i >= j;
  }

 public:
  string shortestPalindrome(string s) {
    if (s.empty()) {
      return s;
    }

    int j = s.size();
    for (; j >= 0; --j) {
      string t = s.substr(0, j);
      if (isPalindrome(t)) {
        break;
      }
    }

    string tail = s.substr(j);
    string body = s.substr(0, j);
    string head = string(tail.rbegin(), tail.rend());

    return head + body + tail;
  }
};
// Time Limit Exceeded
// 2022.6.16 at 奥盛大厦

class Solution {
 public:
  string shortestPalindrome(string s) {
    string t = string(s.rbegin(), s.rend());

    for (int i = 0; i < t.size(); ++i) {
      string u = t.substr(i);
      string v = s.substr(0, t.size() - i);

      if (u == v) {
        return t.substr(0, i) + s;
      }
    }

    return "";
  }
};
// Time Limit Exceeded
// 2022.6.16 at 奥盛大厦

class Solution {
 public:
  string shortestPalindrome(string s) {
    string t = s + "#" + string(s.rbegin(), s.rend());

    vector<int> dp(t.size());
    for (int i = 1, j = 0; i < dp.size(); ++i) {
      if (t[i] == t[j]) {
        dp[i] = ++j;
      } else if (j > 0) {
        j = dp[j - 1];
        --i;
      }
    }

    string body = s.substr(0, dp.back());
    string tail = s.substr(dp.back());
    string head = string(tail.rbegin(), tail.rend());

    return head + body + tail;
  }
};
// Runtime: 3 ms, faster than 89.74%
// Memory Usage: 8.1 MB, less than 31.24%
// 2022.6.17 at 奥盛大厦