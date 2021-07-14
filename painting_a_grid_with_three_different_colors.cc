class Solution {
 public:
  int colorTheGrid(int m, int n) {
    vector<int> states;
    int mod = 1e9 + 7;

    for (int i = 0; i < pow(3, m); ++i) {
      int colorCombinations = i, colorOfPrevRow = -1;

      bool diffColor = true;
      for (int j = 0; j < m; ++j) {
        int colorOfCurrentRow = colorCombinations % 3;
        if (colorOfCurrentRow == colorOfPrevRow) {
          diffColor = false;
          break;
        }

        colorOfPrevRow = colorOfCurrentRow;
        colorCombinations /= 3;
      }

      if (diffColor) {
        states.push_back(i);
      }
    }

    vector<vector<int>> dp(states.size(), vector<int>(n));
    for (int i = 0; i < states.size(); ++i) {
      dp[i][0] = 1;
    }

    for (int j = 1; j < n; ++j) {
      for (int i = 0; i < states.size(); ++i) {
        for (int k = 0; k < states.size(); ++k) {
          if (validColor(states[i], states[k], m)) {
            dp[i][j] = (dp[i][j] + dp[k][j - 1]) % mod;
          }
        }
      }
    }

    int ans = 0;

    for (int i = 0; i < states.size(); ++i) {
      ans = (ans + dp[i][n - 1]) % mod;
    }

    return ans;
  }

 private:
  bool validColor(int color1, int color2, int m) {
    for (int i = 0; i < m; ++i) {
      if (color1 % 3 == color2 % 3) {
        return false;
      }

      color1 /= 3;
      color2 /= 3;
    }

    return true;
  }
};
// Runtime: 176 ms, faster than 61.30%
// Memory Usage: 8.9 MB, less than 77.87%
// 2021.7.14 at 奥盛大厦