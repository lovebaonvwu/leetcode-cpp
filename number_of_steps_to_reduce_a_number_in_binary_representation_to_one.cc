class Solution {
 public:
  int numSteps(string s) {
    int ans = 0;

    while (s != "1") {
      if (s.back() == '0') {
        ++ans;
        s.pop_back();
        continue;
      }

      auto pos = s.rfind('0');
      if (pos == string::npos) {
        ans += s.size() + 1;
        break;
      }

      ans += s.size() - pos;
      s = s.substr(0, pos + 1);
      s.back() = '1';
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 69.78%
// Memory Usage: 7.5 MB, less than 100.00%

class Solution {
 public:
  int numSteps(string s) {
    int ans = 0;
    int carry = 0;

    for (int i = s.size() - 1; i > 0; --i) {
      ++ans;

      if (s[i] - '0' + carry == 1) {
        carry = 1;
        ++ans;
      }
    }

    return ans + carry;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.6 MB, less than 100.00%