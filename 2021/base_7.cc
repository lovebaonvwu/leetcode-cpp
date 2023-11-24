class Solution {
 public:
  string convertToBase7(int num) {
    if (num == 0) {
      return "0";
    }

    string ans;

    int tmp = num < 0 ? -num : num;

    while (tmp > 0) {
      ans += (tmp % 7) + '0';

      tmp /= 7;
    }

    reverse(ans.begin(), ans.end());

    return num < 0 ? "-" + ans : ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 8.87%
// 2021.10.7 at 茗筑美嘉