class Solution {
  vector<vector<int>> ans;

 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    dfs(1, k, n, {});

    return ans;
  }

  void dfs(int i, int k, int n, vector<int> arr) {
    if (k == 1 && n <= 9 && i <= n) {
      arr.push_back(n);
      ans.push_back(arr);
      return;
    }

    if (i > n) {
      return;
    }

    for (int j = i; j <= 9; ++j) {
      arr.push_back(j);
      dfs(j + 1, k - 1, n - j, arr);
      arr.pop_back();
    }
  }
};
// Runtime: 4 ms, faster than 38.28%
// Memory Usage: 7 MB, less than 15.86%