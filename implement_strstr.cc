class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle == "") {
      return 0;
    }

    size_t hl = haystack.size();
    size_t nl = needle.size();
    int len = hl - nl + 1;

    for (int i = 0; i < len; ++i) {
      int j = 0;

      while (j < nl && haystack[i + j] == needle[j]) {
        ++j;
      }

      if (j == nl) {
        return i;
      }
    }

    return -1;
  }
};  // 4ms

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle == "") {
      return 0;
    }

    for (int i = 0; i < haystack.size(); ++i) {
      bool find = true;
      if (haystack[i] == needle[0]) {
        for (int j = 0; j < needle.size(); ++j) {
          if (haystack[i + j] != needle[j]) {
            find = false;
            break;
          }
        }

        if (find) {
          return i;
        }
      }
    }

    return -1;
  }
};  // 1328ms