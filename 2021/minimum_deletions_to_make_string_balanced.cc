class Solution {
 public:
  int minimumDeletions(string s) {
    int cnta = 0;

    for (auto c : s) {
      if (c == 'a') {
        ++cnta;
      }
    }

    int ans = cnta;
    int cntb = 0;
    for (auto c : s) {
      if (c == 'a') {
        --cnta;
      } else {
        ++cntb;
      }

      ans = min(ans, (cnta + cntb));
    }

    return ans;
  }
};
// Runtime: 236 ms, faster than 11.20%
// Memory Usage: 22.4 MB, less than 62.36%