class Solution {
 public:
  int numSub(string s) {
    int ans = 0;

    for (int i = 0, cnt = 0; i < s.size(); ++i) {
      cnt = s[i] == '1' ? cnt + 1 : 0;
      ans = (ans + cnt) % ((int)1e9 + 7);
    }

    return ans;
  }
};
// Runtime: 32 ms, faster than 98.09%
// Memory Usage: 8.8 MB