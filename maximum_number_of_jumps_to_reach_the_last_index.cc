class Solution {
  vector<int> cached;
  int tar;
  int n;

 public:
  int maximumJumps(vector<int>& nums, int target) {
    n = nums.size();
    tar = target;
    cached.resize(n, -1);

    int ans = dfs(nums, 0);
    return ans > 0 ? ans : -1;
  }

  int dfs(const vector<int>& nums, int i) {
    if (i == n - 1) {
      return 0;
    }

    if (cached[i] != -1) {
      return cached[i];
    }

    int cnt = INT_MIN;
    for (int j = i + 1; j < n; ++j) {
      if (abs(nums[j] - nums[i]) <= tar) {
        cnt = max(cnt, 1 + dfs(nums, j));
      }
    }

    return cached[i] = cnt;
  }
};
// Runtime 119 ms
// Memory 61.8 MB