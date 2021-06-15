class Solution {
  int total;
  int used[15] = {0};

 public:
  bool makesquare(vector<int>& matchsticks) {
    total = accumulate(matchsticks.begin(), matchsticks.end(), 0);

    if (total % 4 != 0) {
      return false;
    }

    sort(matchsticks.rbegin(), matchsticks.rend());

    for (int i = 0; i < 4; ++i) {
      if (!dfs(matchsticks, 0)) {
        return false;
      }
    }

    return true;
  }

  bool dfs(vector<int>& m, int sum) {
    if (sum > total / 4) {
      return false;
    }

    if (sum == total / 4) {
      return true;
    }

    for (int i = 0; i < m.size(); ++i) {
      if (!used[i]) {
        used[i] = 1;
        if (dfs(m, sum + m[i])) {
          return true;
        }
        used[i] = 0;
      }
    }

    return false;
  }
};
// Runtime: 216 ms, faster than 20.77%
// Memory Usage: 9.7 MB, less than 73.79%