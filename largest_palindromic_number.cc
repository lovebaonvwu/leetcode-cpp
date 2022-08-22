class Solution {
 public:
  string largestPalindromic(string num) {
    int ch[10] = {0};

    for (auto& n : num) {
      ++ch[n - '0'];
    }

    string head, body, tail;
    for (int i = 9; i >= 0; --i) {
      int cnt = ch[i] / 2;
      if (cnt > 0) {
        string t = string(cnt, i + '0');

        if (i > 0 || !head.empty()) {
          head += t;
          tail += t;
        }
      }

      if (ch[i] % 2 > 0 && body.empty()) {
        body = i + '0';
      }
    }

    reverse(tail.begin(), tail.end());
    string ans = head + body + tail;
    return ans.empty() ? "0" : ans;
  }
};
// Runtime: 15 ms, faster than 100.00%
// Memory Usage: 15.6 MB, less than 100.00%
// 2022.8.22 at 奥盛大厦