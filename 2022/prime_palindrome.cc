class Solution {
  int palindrome(int n, bool odd) {
    string s = std::to_string(n);
    string t(s.rbegin(), s.rend());

    return stoi(s + t.substr(odd ? 1 : 0));
  }

  bool isPrime(int n) {
    if (n < 2 || n % 2 == 0) {
      return n == 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
      if (n % i == 0) {
        return false;
      }
    }

    return true;
  }

 public:
  int primePalindrome(int n) {
    int odd = 1, even = 1;

    int ans = -1;

    while (!(ans >= n && isPrime(ans))) {
      int oddPalindrome = palindrome(odd, true);
      int evenPalindrome = palindrome(even, false);

      ans = min(oddPalindrome, evenPalindrome);
      if (oddPalindrome < evenPalindrome) {
        ++odd;
      } else {
        ++even;
      }
    }

    return ans;
  }
};
// Runtime: 231 ms, faster than 43.25%
// Memory Usage: 6.1 MB, less than 33.73%
// 2022.5.27 at 奥盛大厦