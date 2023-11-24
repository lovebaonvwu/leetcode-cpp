class Solution {
 public:
  int minimumPartition(string s, int k) {
    if (k <= 9) {
      for (auto c : s) {
        if (c - '0' > k) {
          return -1;
        }
      }
    }

    int ans = 0;
    long long val = 0LL;
    for (int i = 0; i < s.size(); ++i) {
      val = val * 10 + (s[i] - '0');
      if (val > k) {
        ++ans;
        val = s[i] - '0';
      }
    }

    return ans + 1;
  }
};
// Runtime 12 ms
// Memory 8.9 MB