class Solution {
 public:
  int minOperations(int k) {
    int ans = k - 1;

    for (int i = 1; i < k; ++i) {
      int op = ceil(k / (i * 1.0));
      ans = min(ans, i - 1 + op - 1);
    }

    return ans;
  }
};
// 5 ms
// 7.40 MB