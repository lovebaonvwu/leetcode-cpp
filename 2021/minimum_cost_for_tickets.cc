class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    return dfs(0, days, costs);
  }

  int dfs(int start, vector<int>& days, vector<int>& costs) {
    if (start >= days.size()) {
      return 0;
    }

    int res = INT_MAX;

    int day1 = upper_bound(days.begin(), days.end(), days[start] + 1 - 1) -
               days.begin();
    int day7 = upper_bound(days.begin(), days.end(), days[start] + 7 - 1) -
               days.begin();
    int day30 = upper_bound(days.begin(), days.end(), days[start] + 30 - 1) -
                days.begin();

    res = min(costs[0] + dfs(day1, days, costs),
              costs[1] + dfs(day7, days, costs));
    res = min(res, costs[2] + dfs(day30, days, costs));

    return res;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> mem(days.size());
    return dfs(0, days, costs, mem);
  }

  int dfs(int start, vector<int>& days, vector<int>& costs, vector<int>& mem) {
    if (start >= days.size()) {
      return 0;
    } else if (mem[start] > 0) {
      return mem[start];
    }

    int res = INT_MAX;

    int day1 = upper_bound(days.begin(), days.end(), days[start] + 1 - 1) -
               days.begin();
    int day7 = upper_bound(days.begin(), days.end(), days[start] + 7 - 1) -
               days.begin();
    int day30 = upper_bound(days.begin(), days.end(), days[start] + 30 - 1) -
                days.begin();

    res = min(costs[0] + dfs(day1, days, costs, mem),
              costs[1] + dfs(day7, days, costs, mem));
    res = min(res, costs[2] + dfs(day30, days, costs, mem));

    return mem[start] = res;
  }
};
// Runtime: 8 ms, faster than 56.67%
// Memory Usage: 9.8 MB, less than 38.04%

class Solution {
 public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> dp(366);

    for (auto day : days) {
      dp[day] = 1;
    }

    for (int i = days[0]; i < 366; ++i) {
      if (!dp[i]) {
        dp[i] = dp[i - 1];
        continue;
      }

      dp[i] = min(dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1]);
      dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]);
    }

    return dp.back();
  }
};
// Runtime: 4 ms, faster than 93.37%
// Memory Usage: 9.4 MB, less than 82.52%