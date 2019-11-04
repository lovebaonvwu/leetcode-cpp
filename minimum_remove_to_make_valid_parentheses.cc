class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    int cnt = 0;

    for (auto& ch : s) {
      if (ch == '(') {
        ++cnt;
      } else if (ch == ')' && cnt > 0) {
        --cnt;
      } else if (ch == ')') {
        ch = '*';
      }
    }

    for (int i = s.size() - 1; i >= 0 && cnt > 0; --i) {
      if (s[i] == '(') {
        s[i] = '*';
        --cnt;
      }
    }

    s.erase(remove(s.begin(), s.end(), '*'), s.end());

    return s;
  }
};
// Runtime: 24 ms, faster than 100.00%
// Memory Usage: 12.1 MB, less than 100.00%

class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    string tmp;

    int cnt = 0;

    for (const auto& ch : s) {
      if (isalpha(ch)) {
        tmp += ch;
        continue;
      }

      if (ch == '(') {
        ++cnt;
        tmp += ch;
      } else if (cnt > 0) {
        --cnt;

        if (cnt >= 0) {
          tmp += ch;
        }
      }
    }

    string ans;

    for (int i = tmp.size() - 1; i >= 0; --i) {
      if (tmp[i] == '(' && cnt > 0) {
        --cnt;
        continue;
      }
      ans = tmp[i] + ans;
    }

    return ans;
  }
};
// Memory Limit Exceeded