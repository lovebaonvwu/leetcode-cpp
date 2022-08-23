class Solution {
 public:
  string shiftingLetters(string s, vector<vector<int>>& shifts) {
    int n = s.size();
    vector<int> mark(n + 1);

    for (auto& shift : shifts) {
      int start = shift[0];
      int end = shift[1] + 1;
      if (shift[2] == 0) {
        --mark[start];
        ++mark[end];
      } else {
        ++mark[start];
        --mark[end];
      }
    }

    for (int i = 0, shift = 0; i < n; ++i) {
      shift = (mark[i] + shift) % 26;
      if (shift > 0) {
        s[i] = (s[i] - 'a' + shift) % 26 + 'a';
      } else if (shift < 0) {
        s[i] = (26 + (s[i] - 'a' + shift)) % 26 + 'a';
      }
    }

    return s;
  }
};
// Runtime: 353 ms, faster than 100.00%
// Memory Usage: 93.1 MB, less than 80.00%
// 2022.8.23 at 奥盛大厦