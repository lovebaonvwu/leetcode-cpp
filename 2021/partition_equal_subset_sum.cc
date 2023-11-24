class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum % 2) {
      return false;
    }

    sum /= 2;

    vector<vector<bool>> dp(nums.size(), vector<bool>(sum + 1));

    dp[0][0] = true;

    for (int i = 1; i < dp.size(); ++i) {
      dp[i][0] = true;
    }

    for (int j = 1; j < dp[0].size(); ++j) {
      dp[0][j] = false;
    }

    for (int i = 1; i < dp.size(); ++i) {
      for (int j = 1; j < dp[0].size(); ++j) {
        dp[i][j] = dp[i - 1][j];

        if (j >= nums[i - 1]) {
          dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
        }
      }
    }

    return dp[dp.size() - 1][dp[0].size() - 1];
  }
};
// Time Limit Exceeded

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum % 2) {
      return false;
    }

    sum /= 2;

    bitset<10001> bits(1);

    for (auto n : nums) {
      bits |= bits << n;
    }

    return bits[sum];
  }
};
// Runtime: 16 ms, faster than 94.53%
// Memory Usage: 9.3 MB, less than 88.13%

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum % 2) {
      return false;
    }

    sum /= 2;

    vector<bool> ss(10001);

    for (auto n : nums) {
      for (int i = 10000; i >= 0; --i) {
        if (ss[i] && i + n < 10001) {
          ss[i + n] = true;
        }
      }
      ss[n] = true;
    }

    return ss[sum];
  }
};
// Runtime: 1648 ms, faster than 5.08%
// Memory Usage: 9.3 MB, less than 88.13%

class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum % 2) {
      return false;
    }

    sum /= 2;

    vector<bool> ss(sum + 1);
    ss[0] = true;

    for (auto n : nums) {
      for (int i = ss.size() - 1; i >= 0; --i) {
        if (i - n >= 0) {
          ss[i] = ss[i] || ss[i - n];
        }
      }
    }

    return ss[sum];
  }
};
// Runtime: 560 ms, faster than 25.26%
// Memory Usage: 9.5 MB, less than 74.00%