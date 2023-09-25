class Solution {
 public:
  long long maximumSumOfHeights(vector<int>& maxHeights) {
    long long ans = 0;
    int n = maxHeights.size();
    for (int k = 0; k < n; ++k) {
      long long sum = maxHeights[k];
      for (int i = k - 1, prev = maxHeights[k]; i >= 0; --i) {
        sum += min(maxHeights[i], prev);
        prev = min(maxHeights[i], prev);
      }
      for (int j = k + 1, prev = maxHeights[k]; j < n; ++j) {
        sum += min(maxHeights[j], prev);
        prev = min(maxHeights[j], prev);
      }

      ans = max(ans, sum);
    }

    return ans;
  }
};
// 76ms
// 24.09MB