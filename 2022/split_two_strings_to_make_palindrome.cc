class Solution {
  bool isPalindrome(const string& s, int i, int j) {
    while (i < j) {
      if (s[i++] != s[j--]) {
        return false;
      }
    }

    return true;
  }

  bool check(const string& a, const string& b) {
    int i = 0, j = a.size() - 1;

    while (i < j && a[i] == b[j]) {
      ++i, --j;
    }

    return isPalindrome(a, i, j) || isPalindrome(b, i, j);
  }

 public:
  bool checkPalindromeFormation(string a, string b) {
    return check(a, b) || check(b, a);
  }
};
// Runtime: 80 ms, faster than 86.75%
// Memory Usage: 24.1 MB, less than 89.16%
// 2022.4.14 at 奥盛大厦