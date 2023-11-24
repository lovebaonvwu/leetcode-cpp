class Solution {
 public:
  int maximumPopulation(vector<vector<int>>& logs) {
    int cnt = 0;

    vector<int> y(100);
    for (auto& log : logs) {
      for (int i = log[0]; i < log[1]; ++i) {
        ++y[i - 1950];

        cnt = max(cnt, y[i - 1950]);
      }
    }

    for (int i = 0; i < y.size(); ++i) {
      if (y[i] == cnt) {
        return i + 1950;
      }
    }

    return 0;
  }
};
// Runtime: 4 ms, faster than 85.92%
// Memory Usage: 8 MB, less than 56.41%

class Solution {
 public:
  int maximumPopulation(vector<vector<int>>& logs) {
    int cnt = 0;

    vector<int> y(2051);
    for (auto& log : logs) {
      ++y[log[0]];
      --y[log[1]];
    }

    int ans = 0;

    for (int i = 1950; i < 2051; ++i) {
      y[i] += y[i - 1];

      ans = y[i] > y[ans] ? i : ans;
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 85.92%
// Memory Usage: 8.4 MB, less than 14.60%