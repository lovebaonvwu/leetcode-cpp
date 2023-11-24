class Solution {
 public:
  int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    int ans = 0;

    ans += min(numOnes, k);
    k -= ans;

    return (k <= numZeros) ? ans : (ans -= min(numNegOnes, k - numZeros));
  }
};
// Runtime 8 ms
// Memory 6 MB