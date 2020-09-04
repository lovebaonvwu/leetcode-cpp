class Solution {
 public:
  string thousandSeparator(int n) {
    string ans;

    for (int cnt = 0; n > 0; n /= 10, ++cnt) {
      if (cnt != 0 && cnt % 3 == 0) {
        ans = '.' + ans;
      }

      ans = (char)((n % 10) + '0') + ans;
    }

    return ans.empty() ? "0" : ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.8 MB, less than 99.98%