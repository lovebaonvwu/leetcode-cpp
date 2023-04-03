class Solution {
 public:
  int findTheLongestBalancedSubstring(string s) {
    int ans = 0;
    for (int i = 0, cnt0 = 0, cnt1 = 0; i < s.size(); ++i) {
      if (s[i] == '0') {
        if (cnt1 > 0) {
          cnt0 = 0;
        }
        ++cnt0;
        cnt1 = 0;
      } else {
        ++cnt1;
        if (cnt1 == cnt0) {
          ans = max(ans, cnt0 + cnt1);
          cnt0 = 0;
        } else if (cnt1 < cnt0) {
          ans = max(ans, 2 * cnt1);
        } else {
          cnt0 = 0;
        }
      }
    }

    return ans;
  }
};
// Runtime 0 ms
// Memory 6.3 MB

class Solution {
 public:
  int findTheLongestBalancedSubstring(string s) {
    int ans = 0;
    for (int i = 0, cnt0 = 0, cnt1 = 0; i < s.size(); ++i) {
      if (s[i] == '0') {
        if (cnt1 > 0) {
          cnt0 = 0;
        }

        ++cnt0;
        cnt1 = 0;
      } else {
        ++cnt1;
        if (cnt1 >= cnt0) {
          ans = max(ans, 2 * cnt0);
          cnt0 = 0;
        } else if (cnt1 < cnt0) {
          ans = max(ans, 2 * cnt1);
        }
      }
    }

    return ans;
  }
};
// Runtime 4 ms
// Memory 6.2 MB