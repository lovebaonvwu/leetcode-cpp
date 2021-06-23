class Solution {
 public:
  int minFlips(string s) {
    int n = s.size();

    s += s;

    string s1 = s;
    string s2 = s;

    for (int i = 0; i < s.size(); ++i) {
      s1[i] = i % 2 ? '0' : '1';
      s2[i] = i % 2 ? '1' : '0';
    }

    int cnt1 = 0, cnt2 = 0, ans = INT_MAX;

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != s1[i])
        ++cnt1;
      if (s[i] != s2[i])
        ++cnt2;

      if (i >= n) {
        if (s[i - n] != s1[i - n])
          --cnt1;
        if (s[i - n] != s2[i - n])
          --cnt2;
      }

      if (i >= n - 1) {
        ans = min({ans, cnt1, cnt2});
      }
    }

    return ans;
  }
};
// Runtime: 60 ms, faster than 63.20%
// Memory Usage: 18.6 MB, less than 59.04%