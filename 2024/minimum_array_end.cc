class Solution {
 public:
  long long minEnd(int n, int x) {
    long long ans = x;
    while (--n > 0) {
      ans = (ans + 1) | x;
    }

    return ans;
  }
};
// 1728 ms
// 7.78 MB