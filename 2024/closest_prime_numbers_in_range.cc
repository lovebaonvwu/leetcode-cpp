class Solution {
  vector<int> buildPrimes(int n) {
    vector<int> primes(n + 1, true);
    primes[0] = false;
    primes[1] = false;

    for (int i = 2; i * i <= n; ++i) {
      if (primes[i]) {
        for (int j = i * i; j <= n; j += i) {
          primes[j] = false;
        }
      }
    }

    // vector<int> ret;
    // for (int i = 0; i <= n; ++i) {
    //     if (primes[i]) {
    //         ret.push_back(i);
    //     }
    // }

    return primes;
  }

 public:
  vector<int> closestPrimes(int left, int right) {
    vector<int> primes = buildPrimes(right);

    int diff = right - left + 1;
    vector<int> ans(2, -1);
    for (int i = left, j = -1; i <= right; ++i) {
      if (primes[i]) {
        if (j != -1) {
          if (i - j < diff) {
            diff = i - j;
            ans[0] = j;
            ans[1] = i;
          }
        }

        j = i;
      }
    }

    return ans;
  }
};
// 130 ms
// 157.55 MB