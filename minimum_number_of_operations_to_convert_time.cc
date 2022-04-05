class Solution {
  int getMin(const string& s) {
    int hour = (s[0] - '0') * 10 + (s[1] - '0');
    int min = (s[3] - '0') * 10 + (s[4] - '0');

    return hour * 60 + min;
  }

 public:
  int convertTime(string current, string correct) {
    int diff = getMin(correct) - getMin(current);

    int ans = 0;

    if (diff >= 60) {
      ans += diff / 60;
      diff %= 60;
    }

    if (diff >= 15) {
      ans += diff / 15;
      diff %= 15;
    }

    if (diff >= 5) {
      ans += diff / 5;
      diff %= 5;
    }

    return ans += diff;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.8 MB, less than 91.95%
// 2022.4.5 at 茗筑美嘉