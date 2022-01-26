class Solution {
 public:
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if (desiredTotal <= 0) {
      return true;
    }

    if ((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) {
      return false;
    }

    vector<char> memo(1 << maxChoosableInteger);

    return dfs(memo, maxChoosableInteger, desiredTotal, 0);
  }

  bool dfs(vector<char>& memo, int n, int target, int state) {
    if (target <= 0) {
      return false;
    }

    if (memo[state]) {
      return memo[state] == 1;
    }

    for (int i = 0; i < n; ++i) {
      if (state & (1 << i)) {
        continue;
      }

      if (!dfs(memo, n, target - (i + 1), state | (1 << i))) {
        memo[state] = 1;
        return true;
      }
    }

    memo[state] = -1;
    return false;
  }
};
// Runtime: 88 ms, faster than 81.44%
// Memory Usage: 17.1 MB, less than 70.40%
// 2022.1.26 at 奥盛大厦