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

    return primes;
  }

 public:
  int maximumPrimeDifference(vector<int>& nums) {
    vector<int> primes = buildPrimes(100);

    int i = -1;
    int j = -1;
    for (int k = 0; k < nums.size(); ++k) {
      if (primes[nums[k]]) {
        if (i == -1) {
          i = k;
          j = k;
        } else {
          j = k;
        }
      }
    }

    return j - i;
  }
};
// 90 ms
// 107.58 MB
