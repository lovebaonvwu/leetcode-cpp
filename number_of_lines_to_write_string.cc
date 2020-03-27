class Solution {
 public:
  vector<int> numberOfLines(vector<int>& widths, string S) {
    int lines = 1;
    int cnt = 0;

    for (auto ch : S) {
      if (cnt + widths[ch - 'a'] > 100) {
        ++lines;
        cnt = widths[ch - 'a'];
      } else {
        cnt += widths[ch - 'a'];
      }
    }

    return {lines, cnt};
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.5 MB, less than 100.00%