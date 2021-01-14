class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    int ans = dfs(nums, 0, nums.size() - 1, x);

    return ans == INT_MAX ? -1 : ans;
  }

  int dfs(vector<int>& nums, int l, int r, int x) {
    if (l > r) {
      return INT_MAX;
    }

    if (x == nums[l] || x == nums[r]) {
      return 1;
    }

    int res = 0;
    res =
        min(dfs(nums, l + 1, r, x - nums[l]), dfs(nums, l, r - 1, x - nums[r]));

    return res == INT_MAX ? res : res + 1;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    int n = nums.size();

    vector<vector<int>> memo(n, vector<int>(n));
    int ans = dfs(nums, 0, nums.size() - 1, x, memo);

    return ans == INT_MAX ? -1 : ans;
  }

  int dfs(vector<int>& nums, int l, int r, int x, vector<vector<int>>& memo) {
    if (l > r) {
      return INT_MAX;
    }

    if (x == nums[l] || x == nums[r]) {
      return 1;
    }

    if (memo[l][r] > 0) {
      return memo[l][r];
    }

    int res = 0;
    res = min(dfs(nums, l + 1, r, x - nums[l], memo),
              dfs(nums, l, r - 1, x - nums[r], memo));

    return memo[l][r] = res == INT_MAX ? res : res + 1;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int minOperations(vector<int>& nums, int x) {
    x = accumulate(nums.begin(), nums.end(), 0) - x;

    if (x < 0) {
      return -1;
    } else if (x == 0) {
      return nums.size();
    }

    int ans = INT_MAX;

    for (int fast = 0, slow = 0, sum = 0, n = nums.size(); fast < n; ++fast) {
      sum += nums[fast];

      if (sum == x) {
        ans = min(ans, n - (fast - slow + 1));
      } else if (sum > x) {
        sum -= nums[slow++];
        sum -= nums[fast--];
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
// Runtime: 120 ms, faster than 100.00%
// Memory Usage: 98.4 MB, less than 100.00%