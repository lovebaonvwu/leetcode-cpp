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

class Solution {
  int total;
  int used[15] = {0};

 public:
  bool makesquare(vector<int>& matchsticks) {
    total = accumulate(matchsticks.begin(), matchsticks.end(), 0);

    if (matchsticks.size() < 4 || total % 4 != 0) {
      return false;
    }

    return dfs(matchsticks, total / 4, 0, 0, 4);
  }

  bool dfs(vector<int>& m, int tar, int sum, int i, int side) {
    if (side == 1) {
      return true;
    }

    if (sum == tar) {
      return dfs(m, tar, 0, 0, side - 1);
    }

    for (int j = i; j < m.size(); ++j) {
      if (used[j] || sum + m[j] > tar) {
        continue;
      }

      used[j] = 1;
      if (dfs(m, tar, sum + m[j], j + 1, side)) {
        return true;
      }
      used[j] = 0;
    }

    return false;
  }
};
// Runtime: 629 ms, faster than 35.24%
// Memory Usage: 10.1 MB, less than 66.64%
// 2022.7.12 at 奥盛大厦