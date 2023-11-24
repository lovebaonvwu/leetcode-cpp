class Solution {
 public:
  string reverseStr(string s, int k) {
    int begin = 0;

    while (begin + 2 * k < s.size() || begin < s.size()) {
      int i = begin;
      int j = begin + k - 1 < s.size() - 1 ? begin + k - 1 : s.size() - 1;

      while (i < j) {
        swap(s[i++], s[j--]);
      }

      begin += 2 * k;
    }

    return s;
  }
};  // 8ms

class Solution {
 public:
  string reverseStr(string s, int k) {
    int begin = 0;

    while (begin + 2 * k < s.size()) {
      int i = begin;
      int j = begin + k - 1;

      while (i < j) {
        swap(s[i++], s[j--]);
      }

      begin += 2 * k;
    }

    if (begin < s.size()) {
      int i = begin;
      int j = begin + k - 1 < s.size() - 1 ? begin + k - 1 : s.size() - 1;

      while (i < j) {
        swap(s[i++], s[j--]);
      }
    }

    return s;
  }
};  // 8ms