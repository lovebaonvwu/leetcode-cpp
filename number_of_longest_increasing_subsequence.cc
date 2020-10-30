class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    vector<pair<int, int>> mem(nums.size());

    pair<int, int> res{0, 0};
    for (int i = 0; i < nums.size(); ++i) {
      auto p = dfs(nums, mem, i);

      if (p.first > res.first) {
        res.first = p.first;
        res.second = p.second;
      } else if (p.first == res.first) {
        res.second += p.second;
      }
    }

    return res.second;
  }

  pair<int, int> dfs(vector<int>& nums,
                     vector<pair<int, int>>& mem,
                     int start) {
    if (mem[start].first > 0) {
      return mem[start];
    }

    pair<int, int> res{0, 1};

    for (int i = start + 1; i < nums.size(); ++i) {
      if (nums[i] > nums[start]) {
        auto p = dfs(nums, mem, i);

        if (p.first > res.first) {
          res.first = p.first;
          res.second = p.second;
        } else if (p.first == res.first) {
          res.second += p.second;
        }
      }
    }

    res.first += 1;

    mem[start] = res;

    return res;
  }
};
// Runtime: 120 ms, faster than 25.34%
// Memory Usage: 14 MB, less than 8.13%

class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    vector<pair<int, int>> dp(nums.size(), {1, 1});

    for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          if (dp[i].first < dp[j].first) {
            dp[i].first = dp[j].first;
            dp[i].second = dp[j].second;
          } else if (dp[i].first == dp[j].first) {
            dp[i].second += dp[j].second;
          }
        }
      }

      dp[i].first += 1;
    }

    int max_len = 0;
    int ans = 0;

    for (auto d : dp) {
      if (d.first > max_len) {
        max_len = d.first;
        ans = d.second;
      } else if (d.first == max_len) {
        ans += d.second;
      }
    }

    return ans;
  }
};
// Runtime: 120 ms, faster than 25.34%
// Memory Usage: 13.4 MB, less than 8.13%

class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    vector<pair<int, int>> dp(nums.size(), {1, 1});

    for (int i = 1; i < nums.size(); ++i) {
      int max_len = 0;
      int max_cnt = 1;

      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          if (dp[j].first > max_len) {
            max_len = dp[j].first;
            max_cnt = dp[j].second;
          } else if (dp[j].first == max_len) {
            max_cnt += dp[j].second;
          }
        }
      }

      dp[i].first = max_len + 1;
      dp[i].second = max_cnt;
    }

    int max_len = 0;
    int ans = 0;

    for (auto d : dp) {
      if (d.first > max_len) {
        max_len = d.first;
        ans = d.second;
      } else if (d.first == max_len) {
        ans += d.second;
      }
    }

    return ans;
  }
};
// Runtime: 100 ms, faster than 34.76%
// Memory Usage: 13.3 MB, less than 8.13%

class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    vector<pair<int, int>> dp(nums.size(), {1, 1});

    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) {
          if (dp[j].first + 1 > dp[i].first) {
            dp[i].first = dp[j].first + 1;
            dp[i].second = dp[j].second;
          } else if (dp[j].first + 1 == dp[i].first) {
            dp[i].second += dp[j].second;
          }
        }
      }
    }

    int max_len = 0;
    int ans = 0;

    for (auto d : dp) {
      if (d.first > max_len) {
        max_len = d.first;
        ans = d.second;
      } else if (d.first == max_len) {
        ans += d.second;
      }
    }

    return ans;
  }
};
// Runtime: 120 ms, faster than 25.34%
// Memory Usage: 13.5 MB, less than 8.13%