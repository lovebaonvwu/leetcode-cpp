class Solution {
 public:
  string reverseWords(string s) {
    reverse(s.begin(), s.end());

    int storeIndex = 0;

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != ' ') {
        if (storeIndex != 0) {
          s[storeIndex++] = ' ';
        }

        int j = i;

        while (j < s.size() && s[j] != ' ') {
          s[storeIndex++] = s[j++];
        }

        reverse(s.begin() + storeIndex - (j - i), s.begin() + storeIndex);

        i = j;
      }
    }

    s.erase(s.begin() + storeIndex, s.end());

    return s;
  }
};
// Runtime: 4 ms, faster than 98.62%
// Memory Usage: 9.6 MB, less than 94.59%

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