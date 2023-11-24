class Solution {
 public:
  vector<int> divisibilityArray(string word, int m) {
    int n = word.size();

    vector<int> ans(n);
    long long c = 0LL;
    for (int i = 0; i < n; ++i) {
      c = c * 10 + (word[i] - '0');

      if (c % m == 0) {
        ans[i] = 1;
        c = 0;
      } else {
        ans[i] = 0;
        c = c % m;
      }
    }

    return ans;
  }
};
// Runtime 54 ms
// Memory 21.7 MB
// 2023.3.1 at 奥盛大厦