class Solution {
  vector<int> ans;

 public:
  vector<int> lexicalOrder(int n) {
    dfs(0, n);

    return ans;
  }

  void dfs(int x, int n) {
    for (int i = 0; i <= 9; ++i) {
      int num = x * 10 + i;

      if (num > 0 && num <= n) {
        ans.push_back(num);
        dfs(num, n);
      }
    }
  }
};
// Runtime: 12 ms, faster than 63.79%
// Memory Usage: 11.5 MB, less than 40.95%