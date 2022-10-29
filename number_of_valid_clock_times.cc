class Solution {
 public:
  int countTime(string time) {
    char& a = time[0];
    char& b = time[1];
    char& c = time[3];
    char& d = time[4];

    int ans = 1;
    ans *= d == '?' ? 10 : 1;
    ans *= c == '?' ? 6 : 1;
    if (a == '?' && b == '?') {
      ans *= 24;
    } else if (a == '?') {
      ans *= b < '4' ? 3 : 2;
    } else if (b == '?') {
      ans *= a == '2' ? 4 : 10;
    }

    return ans;
  }
};
// Runtime: 5 ms, faster than 21.59%
// Memory Usage: 5.8 MB, less than 99.85%
// 2022.10.29 at 奥盛大厦