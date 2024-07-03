class Solution {
 public:
  int tripletCount(vector<int>& a, vector<int>& b, vector<int>& c) {
    int ans = 0;
    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < b.size(); ++j) {
        for (int k = 0; k < c.size(); ++k) {
          int n = a[i] ^ b[j] ^ c[k];

          int cnt = 0;
          for (int p = 0; p < 31; ++p) {
            cnt += (n >> p) & 1;
          }

          ans += cnt % 2 == 0;
        }
      }
    }
    return ans;
  }
};
// 240 ms
// 46.82 MB