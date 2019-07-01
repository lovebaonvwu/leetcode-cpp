class Solution {
 public:
  bool validPalindrome(string s) {
    int begin = 0;
    int end = s.size() - 1;

    while (begin < end) {
      if (s[begin] != s[end]) {
        if (isValid(s, begin + 1, end)) {
          return true;
        }

        if (isValid(s, begin, end - 1)) {
          return true;
        }

        return false;
      }

      ++begin;
      --end;
    }

    return true;
  }

  bool isValid(string& s, int i, int j) {
    while (i < j) {
      if (s[i++] != s[j--]) {
        return false;
      }
    }

    return true;
  }
};  // 100ms

class Solution {
 public:
  bool validPalindrome(string s) {
    int begin = 0;
    int end = s.size() - 1;
    bool valid = true;

    while (begin < end) {
      if (s[begin] != s[end]) {
        valid = false;
        break;
      }

      ++begin;
      --end;
    }

    if (valid) {
      return true;
    }

    return isValid(s, begin + 1, end) || isValid(s, begin, end - 1);
  }

  bool isValid(string& s, int i, int j) {
    while (i < j) {
      if (s[i++] != s[j--]) {
        return false;
      }
    }

    return true;
  }
};  // 108ms

class Solution {
 public:
  bool validPalindrome(string s) {
    int begin = 0;
    int end = s.size() - 1;

    while (begin < end) {
      if (s[begin] != s[end]) {
        return isValid(s, begin + 1, end) || isValid(s, begin, end - 1);
      }

      ++begin;
      --end;
    }

    return true;
  }

  bool isValid(string& s, int i, int j) {
    while (i < j) {
      if (s[i++] != s[j--]) {
        return false;
      }
    }

    return true;
  }
};  // 112ms