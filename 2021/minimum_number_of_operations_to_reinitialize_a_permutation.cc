class Solution {
 public:
  int reinitializePermutation(int n) {
    vector<int> perm(n);
    vector<int> arr(n);

    for (int i = 0; i < n; ++i) {
      perm[i] = i;
      arr[i] = i;
    }

    int ans = 0;
    do {
      ++ans;
      vector<int> tmp(n);

      for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
          tmp[i] = arr[i / 2];
        } else {
          tmp[i] = arr[n / 2 + (i - 1) / 2];
        }
      }

      arr = tmp;
    } while (arr != perm);

    return ans;
  }
};
// Runtime: 32 ms, faster than 41.75%
// Memory Usage: 25.8 MB, less than 13.57%

class Solution {
 public:
  int reinitializePermutation(int n) {
    if (n == 2) {
      return 1;
    }

    int ans = 1;

    int index_of_1 = 2;

    while (index_of_1 != 1) {
      index_of_1 = (index_of_1 * 2) % (n - 1);
      ++ans;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.7 MB, less than 97.66%