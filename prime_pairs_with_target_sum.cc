class Solution {
 public:
  vector<vector<int>> findPrimePairs(int n) {
    vector<int> primes(n + 1, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i * i <= n; ++i) {
      if (primes[i]) {
        for (int j = i * 2; j <= n; j += i) {
          primes[j] = false;
        }
      }
    }

    vector<vector<int>> ans;
    for (int i = 2; i + i <= n; ++i) {
      if (primes[i] && primes[n - i]) {
        ans.push_back({i, n - i});
      }
    }

    return ans;
  }
};
// Runtime 500 ms
// Memory 206.7 MB