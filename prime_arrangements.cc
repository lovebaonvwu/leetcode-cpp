class Solution {
 public:
  int numPrimeArrangements(int n) {
    unordered_set<int> st = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                             43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    int p = 0, q = 0;
    for (int i = 1; i <= n; ++i) {
      if (st.count(i)) {
        ++p;
      } else {
        ++q;
      }
    }

    long long ans = 1;

    for (int i = 1; i <= p; ++i) {
      ans = (ans * i) % 1000000007;
    }

    for (int i = 1; i <= q; ++i) {
      ans = (ans * i) % 1000000007;
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 12.57%