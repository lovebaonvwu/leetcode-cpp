class Solution {
 public:
  string breakPalindrome(string palindrome) {
    if (palindrome.size() == 1) {
      return "";
    }

    int n = palindrome.size();
    for (int i = 0; i < n; ++i) {
      if ((n & 1) && i == (n / 2)) {
        continue;
      }

      if (palindrome[i] != 'a') {
        palindrome[i] = 'a';
        break;
      }

      if (i == n - 1) {
        palindrome[i] = 'b';
      }
    }

    return palindrome;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 88.12%