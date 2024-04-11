class Solution {
  vector<int> buildPrimes(int n) {
    vector<int> primes(n + 1);
    for (int i = 2; i <= n; ++i) {
      if (primes[i] == false) {
        for (int j = i + i; j <= n; j += i) {
          primes[j] = true;
        }
      }
    }

    vector<int> ret;
    for (int i = 2; i <= n; ++i) {
      if (primes[i] == false) {
        ret.push_back(i);
      }
    }

    return ret;
  }

 public:
  int smallestValue(int n) {
    vector<int> primes = buildPrimes(n);

    function<int(int)> sumOfPrime = [&](int n) -> int {
      int ret = 0;
      int i = 0;
      while (n > 1) {
        if (i < primes.size() && n % primes[i] == 0) {
          ret += primes[i];
          n /= primes[i];
          continue;
        }

        i += 1;
      }
      return ret;
    };

    int prev = 0;
    while (n != prev) {
      prev = n;
      n = sumOfPrime(n);
    }

    return prev;
  }
};
// 53 ms
// 46.76 MB