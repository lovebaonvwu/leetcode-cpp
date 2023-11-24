class Solution {
 public:
  int smallestRepunitDivByK(int K) {
    vector<int> seen(K);

    for (int i = 1; !seen[i % K]; i = (i % K) * 10 + 1) {
      seen[i % K] = 1;
    }

    return seen[0] ? count_if(seen.begin(), seen.end(),
                              [](int i) { return i == 1; })
                   : -1;
  }
};
// Runtime: 4 ms, faster than 56.99%
// Memory Usage: 8.7 MB, less than 20.21%

class Solution {
 public:
  int smallestRepunitDivByK(int K) {
    if (K == 1) {
      return 1;
    }

    for (int m = 1, N = 1; N <= K; m = (m * 10 + 1) % K, ++N) {
      if (m == 0)
        return N;
    }

    return -1;
  }
};
// Runtime: 4 ms, faster than 56.99%
// Memory Usage: 6.3 MB, less than 53.89%

class Solution {
 public:
  int smallestRepunitDivByK(int K) {
    vector<int> seen(K + 1);

    for (int i = 1; !seen[i % K]; i = (i * 10 + 1) % K) {
      seen[i % K] = 1;
    }

    return seen[0] ? count_if(seen.begin(), seen.end(),
                              [](int i) { return i == 1; })
                   : -1;
  }
};
// Runtime: 4 ms, faster than 56.99%
// Memory Usage: 8.8 MB, less than 20.21%