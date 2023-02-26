class Solution {
 public:
  int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; ++i) {
      dp[i][0] = i;
    }

    for (int j = 1; j <= n; ++j) {
      dp[0][j] = j;
    }

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
        }
      }
    }

    return dp[m][n];
  }
};
// Runtime 19 ms
// Memory 9.1 MB
// 2023.2.26 at 茗筑美嘉

class Solution {
  vector<vector<int>> memo;

 public:
  int minDistance(string word1, string word2) {
    int l1 = word1.size();
    int l2 = word2.size();

    memo = vector<vector<int>>(l1 + 1, vector<int>(l2 + 1, -1));

    return dfs(word1, word2, l1, l2);
  }

  int dfs(string& w1, string& w2, int l1, int l2) {
    if (l1 == 0) {
      return l2;
    }

    if (l2 == 0) {
      return l1;
    }

    if (memo[l1][l2] >= 0) {
      return memo[l1][l2];
    }

    int ret;
    if (w1[l1 - 1] == w2[l2 - 1]) {
      ret = dfs(w1, w2, l1 - 1, l2 - 1);
    } else {
      ret = min(dfs(w1, w2, l1 - 1, l2 - 1),
                min(dfs(w1, w2, l1 - 1, l2), dfs(w1, w2, l1, l2 - 1))) +
            1;
    }

    return memo[l1][l2] = ret;
  }
};
// Runtime 17 ms
// Memory 9 MB
// 2023.2.26 at  茗筑美嘉
