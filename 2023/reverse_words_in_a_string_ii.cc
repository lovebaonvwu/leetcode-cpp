class Solution {
 public:
  void reverseWords(vector<char>& s) {
    reverse(s.begin(), s.end());

    for (int i = 0, j = 0, k = 0; k <= s.size(); ++k) {
      if (k < s.size() && s[k] != ' ') {
        continue;
      }

      j = k - 1;
      while (i < j) {
        swap(s[i++], s[j--]);
      }

      i = k + 1;
    }
  }
};
// Runtime 22 ms
// Memory 16 MB
// 2023.2.3 at 奥盛大厦