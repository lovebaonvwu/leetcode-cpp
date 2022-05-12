class Solution {
 public:
  string largestGoodInteger(string num) {
    string& s = num;
    int x = -1;

    for (int i = 2; i < s.size(); ++i) {
      if (s[i] == s[i - 1] && s[i] == s[i - 2]) {
        if (s[i] - '0' > x) {
          x = s[i] - '0';
        }
      }
    }

    return x == -1 ? "" : string(3, x + '0');
  }
};
// Runtime: 8 ms, faster than 17.73%
// Memory Usage: 6.5 MB, less than 46.27%
// 2022.5.12 at 奥盛大厦

class Solution {
 public:
  string largestGoodInteger(string num) {
    string& s = num;
    int x = 0;

    for (int i = 2; i < s.size(); ++i) {
      if (s[i] == s[i - 1] && s[i] == s[i - 2]) {
        if (s[i] > x) {
          x = s[i];
        }
      }
    }

    return x == 0 ? "" : string(3, x);
  }
};
// Runtime: 2 ms, faster than 71.60%
// Memory Usage: 6.6 MB, less than 46.27%
// 2022.5.12 at 奥盛大厦