class Solution {
 public:
  int superpalindromesInRange(string left, string right) {
    int lower_bound = max(1, (int)left.size() / 4 - 1);
    int upper_bound = (int)pow(10, right.size() / 4 + 1);

    int ans = 0;
    long long p = 0, super_p = 0, l = stoll(left), r = stoll(right);

    for (int i = lower_bound; i <= upper_bound; ++i) {
      for (auto b : {true, false}) {
        p = createPalindrome(i, b);
        if (p > 1e9) {
          continue;
        }

        super_p = p * p;

        if (super_p >= l && super_p <= r && isPalindrome(p * p)) {
          ++ans;
        }
      }
    }

    return ans;
  }

 private:
  long long createPalindrome(int x, bool oddSize) {
    long long y = x;

    if (oddSize) {
      x /= 10;
    }

    while (x > 0) {
      y = y * 10 + x % 10;
      x /= 10;
    }

    return y;
  }

  bool isPalindrome(long long n) {
    long long m = 0, t = n;

    while (n > 0) {
      m = m * 10 + n % 10;
      n /= 10;
    }

    return m == t;
  }
};
// Runtime: 24 ms, faster than 92.22%
// Memory Usage: 6 MB, less than 93.33%