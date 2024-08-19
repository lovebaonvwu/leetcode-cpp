class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2)));
        if (grid[0][0] == 'X') {
            dp[0][0][0] = 1;
        } else if (grid[0][0] == 'Y') {
            dp[0][0][1] = 1;
        }

        int ans = 0;
        for (int j = 1; j < n; ++j) {
            dp[0][j][0] = dp[0][j - 1][0];
            dp[0][j][1] = dp[0][j - 1][1];
            if (grid[0][j] == 'X') {
                dp[0][j][0] += 1;
            } else if (grid[0][j] == 'Y') {
                dp[0][j][1] += 1;
            }

            if (dp[0][j][0] > 0 && dp[0][j][0] == dp[0][j][1]) {
                ++ans;
            }
        }

        for (int i = 1; i < m; ++i) {
            dp[i][0][0] = dp[i - 1][0][0];
            dp[i][0][1] = dp[i - 1][0][1];
            if (grid[i][0] == 'X') {
                dp[i][0][0] += 1;
            } else if (grid[i][0] == 'Y') {
                dp[i][0][1] += 1;
            }

            if (dp[i][0][0] > 0 && dp[i][0][0] == dp[i][0][1]) {
                ++ans;
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j][0] = dp[i - 1][j][0] + dp[i][j - 1][0] - dp[i - 1][j - 1][0];
                dp[i][j][1] = dp[i - 1][j][1] + dp[i][j - 1][1] - dp[i - 1][j - 1][1];;

                if (grid[i][j] == 'X') {
                    dp[i][j][0] += 1;
                } else if (grid[i][j] == 'Y') {
                    dp[i][j][1] += 1;
                }

                if (dp[i][j][0] > 0 && dp[i][j][0] == dp[i][j][1]) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};
// 811 ms
// 282.58 MB
