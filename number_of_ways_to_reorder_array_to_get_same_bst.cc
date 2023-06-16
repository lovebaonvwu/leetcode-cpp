class Solution {
 public:
  int numOfWays(vector<int>& nums) {
    int mod = 1e9 + 7;
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1));
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
      }
    }
    function<int(vector<int>)> dfs = [&](const vector<int>& nums) {
      int n = nums.size();

      if (n <= 2) {
        return 1;
      }

      vector<int> l, r;
      for (int i = 1; i < n; ++i) {
        if (nums[i] < nums[0]) {
          l.push_back(nums[i]);
        } else if (nums[i] > nums[0]) {
          r.push_back(nums[i]);
        }
      }
      int left = dfs(l);
      int right = dfs(r);

      long long ans = 0;
      ans = dp[n - 1][l.size()];
      ans = (ans * left) % mod;
      ans = (ans * right) % mod;

      return static_cast<int>(ans);
    };

    return dfs(nums) - 1;
  }
};
// Runtime 453 ms
// Memory 179.4 MB