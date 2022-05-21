class Solution {
 public:
  int divisorSubstrings(int num, int k) {
    int ans = 0;

    string s = std::to_string(num);

    for (int i = 0; i <= s.size() - k; ++i) {
      string t = s.substr(i, k);

      int op = std::stoi(t);

      ans += op > 0 && num % op == 0;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 61.19%
// 2022.5.21 at 奥盛大厦

class Solution {
 public:
  int divisorSubstrings(int num, int k) {
    int ans = 0, cur = 0, pow = 1;

    for (int n = num; n > 0; n /= 10) {
      cur += (n % 10) * pow;

      if (--k > 0) {
        pow *= 10;
      } else {
        ans += cur && (num % cur == 0);
        cur /= 10;
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 61.19%