class Solution {
 public:
  string getSmallestString(string s, int k) {
    int n = s.size();
    for (int i = 0; i < n && k > 0; ++i) {
      int val = s[i] - 'a';
      if (val <= k || 26 - val <= k) {
        s[i] = 'a';
        k -= min(val, 26 - val);
      } else {
        s[i] -= k;
        k = 0;
      }
    }

    return s;
  }
};
// 0 ms
// 8.05 MB