class Solution {
 public:
  string reverseWords(string s) {
    istringstream is(s);

    string tmp;
    string ans;

    is >> ans;

    while (is >> tmp) {
      ans = tmp + ' ' + ans;
    }

    return ans;
  }
};
// Runtime: 20 ms, faster than 16.53%
// Memory Usage: 67.1 MB, less than 10.81%

class Solution {
 public:
  string reverseWords(string s) {
    string ans;

    string word;

    for (int i = s.size() - 1; i >= 0; --i) {
      if (isspace(s[i]) && !word.empty()) {
        ans.append(word);
        ans.append(1, ' ');
        word = "";
      } else if (!isspace(s[i])) {
        word = s[i] + word;
      }
    }

    if (!word.empty()) {
      ans.append(word);
    }

    return ans[ans.size() - 1] == ' ' ? ans.substr(0, ans.size() - 1) : ans;
  }
};
// Runtime: 28 ms, faster than 7.86%
// Memory Usage: 15.5 MB, less than 29.73%