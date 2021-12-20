class Solution {
 public:
  string firstPalindrome(vector<string>& words) {
    for (auto& w : words) {
      int i = 0, j = w.size() - 1;

      while (i < j) {
        if (w[i] != w[j]) {
          break;
        }

        ++i, --j;
      }

      if (i >= j) {
        return w;
      }
    }

    return "";
  }
};
// Runtime: 56 ms, faster than 41.67%
// Memory Usage: 19.6 MB, less than 41.67%
// 2021.12.19 at 茗筑美嘉