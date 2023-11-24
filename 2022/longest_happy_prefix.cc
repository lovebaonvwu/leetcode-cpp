class Solution {
 public:
  string longestPrefix(string s) {
    int n = s.size();
    vector<int> table(n);

    int j = 0;
    for (int i = 1; i < n; ++i) {
      if (s[i] == s[j]) {
        table[i] = j + 1;
        ++j;
      } else if (j > 0) {
        j = table[j - 1];
        --i;
      }
    }

    return s.substr(0, j);
  }
};
// Runtime: 50 ms, faster than 55.21%
// Memory Usage: 20.1 MB, less than 59.72%
// 2022.6.16 at 奥盛大厦