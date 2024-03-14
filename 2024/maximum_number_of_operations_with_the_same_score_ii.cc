class Solution {
 public:
  int maxOperations(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> cached(n, vector<int>(n, -1));

    function<int(int, int, int)> dfs = [&](int i, int j, int score) -> int {
      if (i >= j)
        return 0;

      if (cached[i][j] != -1)
        return cached[i][j];

      int ret = 0;

      if (nums[i] + nums[j] == score)
        ret = max(ret, 1 + dfs(i + 1, j - 1, score));

      if (nums[i] + nums[i + 1] == score)
        ret = max(ret, 1 + dfs(i + 2, j, score));

      if (nums[j] + nums[j - 1] == score)
        ret = max(ret, 1 + dfs(i, j - 2, score));

      return cached[i][j] = ret;
    };

    int ans = 0;
    ans = max(ans, 1 + dfs(1, n - 2, nums[0] + nums[n - 1]));
    ans = max(ans, 1 + dfs(2, n - 1, nums[0] + nums[1]));
    ans = max(ans, 1 + dfs(0, n - 3, nums[n - 1] + nums[n - 2]));

    return ans;
  }
};
// 197 ms
// 148.45 MB