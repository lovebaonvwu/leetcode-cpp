class Solution {
 public:
  int jump(vector<int>& nums) {
    if (nums.size() == 1) {
      return 0;
    }

    vector<int> mem(nums.size());

    return dfs(mem, nums, 0);
  }

  int dfs(vector<int>& mem, vector<int>& nums, int start) {
    if (nums[start] == 0) {
      return -1;
    }

    if (start + nums[start] >= nums.size() - 1) {
      return 1;
    }

    if (mem[start] > 0 || mem[start] == -1) {
      return mem[start];
    }

    int ans = -1;
    for (int i = 1; i <= nums[start]; ++i) {
      int res = dfs(mem, nums, start + i);
      if (res < 0) {
        continue;
      }

      if (ans < 0) {
        ans = res;
      }
      ans = min(ans, res);
    }

    mem[start] = ans < 0 ? -1 : ans + 1;

    return mem[start];
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int jump(vector<int>& nums) {
    int ans = 0;
    int farthest = 0;
    int bound = 0;

    for (int i = 0; i < nums.size(); ++i) {
      if (i > bound) {
        ++ans;
        bound = farthest;
      }

      farthest = max(farthest, i + nums[i]);
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 95.11%
// Memory Usage: 8 MB, less than 100.00%

class Solution {
 public:
  int jump(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n, n);

    dp[n - 1] = 0;

    for (int i = n - 2; i >= 0; --i) {
      int range = i + nums[i];

      if (range >= n - 1) {
        dp[i] = 1;
        continue;
      }

      for (int j = range; j > i; --j) {
        dp[i] = min(dp[i], 1 + dp[j]);
      }
    }

    return dp[0];
  }
};
// Time Limit Exceeded