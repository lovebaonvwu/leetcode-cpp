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
    int left = 0;

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ') {
        reverse(s.begin() + left, s.begin() + i);
        left = i + 1;
      }
    }

    reverse(s.begin() + left, s.end());

    return s;
  }
};  // 20ms

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