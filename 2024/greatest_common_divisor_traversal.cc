class Solution {
  int Father[2 * 100005];

  int FindFather(int x) {
    if (Father[x] != x)
      Father[x] = FindFather(Father[x]);
    return Father[x];
  }

  void Union(int x, int y) {
    x = Father[x];
    y = Father[y];
    if (x > y)
      Father[y] = x;
    else
      Father[x] = y;
  }

  vector<int> buildPrimes(int n) {
    vector<bool> nums(n + 1, true);
    nums[0] = false;
    nums[1] = false;
    for (int i = 2; i * i <= n; ++i) {
      if (nums[i]) {
        for (int j = i * i; j <= n; j += i) {
          nums[j] = false;
        }
      }
    }

    vector<int> primes;
    for (int i = 0; i <= n; ++i) {
      if (nums[i]) {
        primes.push_back(i);
      }
    }

    return primes;
  }

 public:
  bool canTraverseAllPairs(vector<int>& nums) {
    int MX = *max_element(begin(nums), end(nums));

    vector<int> primes = buildPrimes(MX);
    int M = primes.size();

    int N = nums.size();

    unordered_map<int, int> idx;
    for (int i = 0; i < M; ++i) {
      idx[primes[i]] = i;
    }

    for (int i = 0; i < N + M; ++i) {
      Father[i] = i;
    }

    for (int i = 0; i < N; ++i) {
      int x = nums[i];

      for (int j = 0; j < M; ++j) {
        int p = primes[j];
        if (p > x) {
          break;
        }

        if (p * p > x) {
          if (FindFather(i) != FindFather(N + idx[x])) {
            Union(i, N + idx[x]);
          }
          break;
        }

        if (x % p == 0) {
          if (FindFather(i) != FindFather(N + j)) {
            Union(i, N + j);
          }

          while (x % p == 0) {
            x /= p;
          }
        }
      }
    }

    for (int i = 0; i < N; ++i) {
      if (FindFather(i) != FindFather(0))
        return false;
    }

    return true;
  }
};
// 252 ms
// 94.2 MB