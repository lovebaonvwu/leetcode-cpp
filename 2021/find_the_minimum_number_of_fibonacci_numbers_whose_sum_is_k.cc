class Solution {
 public:
  int findMinFibonacciNumbers(int k) {
    vector<int> fabs = {1, 1};

    for (int i = 2; fabs[i - 1] + fabs[i - 2] <= k; ++i) {
      fabs.push_back(fabs[i - 1] + fabs[i - 2]);
    }

    int ans = 0;

    while (k > 0) {
      if (fabs.back() > k) {
        fabs.pop_back();
        continue;
      }

      ++ans;

      k -= fabs.back();
      fabs.pop_back();
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 79.71%
// Memory Usage: 6.6 MB, less than 100.00%