class Solution {
 public:
  int maxScore(vector<int>& nums) {
    int l = nums.size();
    vector<vector<int>> cache(1 << l, vector<int>(l / 2 + 1));

    function<int(int, int)> dp = [&](int mask, int k) {
      if (mask == 0) {
        return 0;
      }

      if (cache[mask][k] > 0) {
        return cache[mask][k];
      }

      int ans = 0;
      for (int i = 0; i < l; ++i) {
        for (int j = i + 1; j < l; ++j) {
          if ((mask & (1 << i)) && (mask & (1 << j))) {
            ans = max(ans, k * gcd(nums[i], nums[j]) +
                               dp(mask ^ (1 << i) ^ (1 << j), k + 1));
          }
        }
      }

      return ans;
    };

    return dp((1 << l) - 1, 1);
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int maxScore(vector<int>& nums) {
    int l = nums.size();
    vector<int> cache(1 << l);

    function<int(int)> dp = [&](int mask) {
      if (mask == 0) {
        return 0;
      }

      if (cache[mask] > 0) {
        return cache[mask];
      }

      int k = (l - __builtin_popcount(mask)) / 2 + 1;
      int ans = 0;
      for (int i = 0; i < l; ++i) {
        for (int j = i + 1; j < l; ++j) {
          if ((mask & (1 << i)) && (mask & (1 << j))) {
            ans = max(ans, k * gcd(nums[i], nums[j]) +
                               dp(mask ^ (1 << i) ^ (1 << j)));
          }
        }
      }

      return ans;
    };

    return dp((1 << l) - 1);
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int maxScore(vector<int>& nums) {
    int l = nums.size();
    vector<int> dp(1 << l);

    for (int mask = 0; mask < (1 << l); ++mask) {
      int c = __builtin_popcount(mask);
      if (c & 1) {
        continue;
      }

      int k = c / 2 + 1;
      for (int i = 0; i < l; ++i) {
        for (int j = i + 1; j < l; ++j) {
          if ((mask & (1 << i)) == 0 && (mask & (1 << j)) == 0) {
            int new_mask = mask | (1 << i) | (1 << j);
            dp[new_mask] =
                max(dp[new_mask], k * gcd(nums[i], nums[j]) + dp[mask]);
          }
        }
      }
    }

    return dp[(1 << l) - 1];
  }
};
// Runtime 223 ms
// Memory 8.8 MB