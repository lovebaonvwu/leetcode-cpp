class Solution {
 public:
  int createSortedArray(vector<int>& instructions) {
    const int n = 100001;
    int sum[n] = {0};

    int ans = 0;
    for (auto i : instructions) {
      ans = (ans +
             min(get(i - 1, n, sum), get(100000, n, sum) - get(i, n, sum))) %
            1000000007;
      update(i, i, n, sum);
    }

    return ans;
  }

  void update(int i, int x, int n, int* sum) {
    while (i < n) {
      ++sum[i];
      i += (i & -i);
    }
  }

  int get(int i, int n, int* sum) {
    int t = 0;

    while (i > 0) {
      t += sum[i];
      i -= (i & -i);
    }

    return t;
  }
};
// Runtime: 672 ms, faster than 32.00%
// Memory Usage: 114.7 MB, less than 89.90%