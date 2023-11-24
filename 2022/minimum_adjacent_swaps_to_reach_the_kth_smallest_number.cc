class Solution {
 public:
  int getMinSwaps(string num, int k) {
    string s = num;

    while (k-- > 0) {
      next_permutation(begin(s), end(s));
    }

    int ans = 0;
    for (int i = 0, j = 0; i < s.size(); ++i, j = i) {
      while (num[i] != s[j]) {
        ++j;
      }

      while (i < j) {
        swap(s[j], s[j - 1]);
        ++ans;
        --j;
      }
    }

    return ans;
  }
};
// Runtime: 66 ms, faster than 24.04%
// Memory Usage: 6.5 MB, less than 97.05%
// 2022.10.14 at 奥盛大厦