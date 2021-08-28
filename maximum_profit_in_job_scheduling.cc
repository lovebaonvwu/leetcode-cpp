class Solution {
 public:
  int jobScheduling(vector<int>& startTime,
                    vector<int>& endTime,
                    vector<int>& profit) {
    int n = startTime.size();

    vector<vector<int>> sch(n);

    for (int i = 0; i < startTime.size(); ++i) {
      sch[i].push_back(endTime[i]);
      sch[i].push_back(startTime[i]);
      sch[i].push_back(profit[i]);
    }

    sort(sch.begin(), sch.end());

    vector<int> dp(n);
    dp[0] = sch[0][2];

    int ans = 0;

    for (int i = 1; i < n; ++i) {
      dp[i] = max(dp[i - 1], sch[i][2]);
      for (int j = 0; j < i; ++j) {
        if (sch[j][0] <= sch[i][1]) {
          dp[i] = max(dp[i], dp[j] + sch[i][2]);
        }
      }
    }

    return dp[n - 1];
  }
};
// Time Limit Exceeded
// 2021.8.28 at 茗筑美嘉

class Solution {
 public:
  int jobScheduling(vector<int>& startTime,
                    vector<int>& endTime,
                    vector<int>& profit) {
    int n = startTime.size();

    vector<vector<int>> sch(n);

    for (int i = 0; i < startTime.size(); ++i) {
      sch[i].push_back(endTime[i]);
      sch[i].push_back(startTime[i]);
      sch[i].push_back(profit[i]);
    }

    sort(sch.begin(), sch.end());

    map<int, int> dp{{0, 0}};

    for (auto& s : sch) {
      int profit = prev(dp.upper_bound(s[1]))->second + s[2];

      if (profit > dp.rbegin()->second) {
        dp[s[0]] = profit;
      }
    }

    return dp.rbegin()->second;
  }
};
// Runtime: 472 ms, faster than 11.99%
// Memory Usage: 68.7 MB, less than 20.19%
// 2021.8.28 at 茗筑美嘉