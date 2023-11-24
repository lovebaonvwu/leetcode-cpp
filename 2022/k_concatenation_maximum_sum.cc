class Solution {
 public:
  int kConcatenationMaxSum(vector<int>& arr, int k) {
    long long gmax = 0, curmax = 0;
    int n = arr.size();
    int mod = 1e9 + 7;
    for (int i = 0; i < n * min(2, k); ++i) {
      curmax = max<long long>(arr[i % n], curmax + arr[i % n]);
      gmax = max(gmax, curmax);
    }

    long long ans =
        (gmax +
         max(0LL, max(0, (k - 2)) * accumulate(arr.begin(), arr.end(), 0LL))) %
        mod;

    return ans;
  }
};
// Runtime: 178 ms, faster than 5.15%
// Memory Usage: 39.5 MB, less than 90.46%
// 2022.9.1 at 奥盛大厦