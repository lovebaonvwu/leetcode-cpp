class Solution {
 public:
  string reverseWords(string s) {
    int size = s.size();

    for (int i = 0; i < size;) {
      int j = i;
      for (; j < size && s[j] != ' '; ++j) {
      }

      int tmp = j--;

      while (i < j) {
        swap(s[i++], s[j--]);
      }

      i = tmp + 1;
    }

    return s;
  }
};  // 16ms

class Solution {
 public:
  string reverseWords(string s) {
    for (int i = 0; i < s.size();) {
      int j = i;
      for (; j < s.size() && s[j] != ' '; ++j) {
      }

      int tmp = j--;

      while (i < j) {
        swap(s[i++], s[j--]);
      }

      i = tmp + 1;
    }

    return s;
  }
};  // 24ms