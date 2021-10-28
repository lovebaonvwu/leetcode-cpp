class Solution {
 public:
  int minSwaps(string s) {
    stack<char> stk;

    for (auto c : s) {
      if (c == ']' && !stk.empty() && stk.top() == '[') {
        stk.pop();
      } else {
        stk.push(c);
      }
    }

    return (stk.size() / 2 + 1) / 2;
  }
};
// Runtime: 164 ms, faster than 26.82%
// Memory Usage: 34.3 MB, less than 19.48%
// 2021.10.28 at 奥盛大厦

class Solution {
 public:
  int minSwaps(string s) {
    int cnt = 0, ans = 0, i = 0, j = s.size() - 1;

    for (int i = 0; i < j; ++i) {
      cnt += s[i] == '[' ? 1 : -1;

      if (cnt == -1) {
        while (i < j && s[j] != '[') {
          --j;
        }

        cnt = 1;
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 116 ms, faster than 72.08%
// Memory Usage: 31.3 MB, less than 48.70%
// 2021.10.28 at 奥盛大厦