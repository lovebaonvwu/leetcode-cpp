class Solution {
  vector<int> ans;
  int k;

 public:
  vector<int> numsSameConsecDiff(int N, int K) {
    k = K;

    for (int i = N != 1; i <= 9; ++i) {
      dfs(N - 1, i, i);
    }

    return ans;
  }

  void dfs(int n, int sum, int lastDigit) {
    if (n == 0) {
      ans.push_back(sum);
      return;
    }

    if (lastDigit + k <= 9) {
      dfs(n - 1, sum * 10 + lastDigit + k, lastDigit + k);
    }

    if (k != 0 && lastDigit - k >= 0) {
      dfs(n - 1, sum * 10 + lastDigit - k, lastDigit - k);
    }
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8 MB, less than 52.48%