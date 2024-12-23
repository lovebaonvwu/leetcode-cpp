class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 1e9 + 7;

        vector<vector<vector<int>>> cached(m, vector<vector<int>>(n, vector<int>(16, - 1)));

        function<int(int, int, int)> dfs = [&](int y, int x, int v) -> int {
            if (y == m - 1 && x == n - 1) {
                return v == k;
            }

            if (cached[y][x][v] != -1) {
                return cached[y][x][v];
            }

            int ret = 0;
            if (y + 1 <= m - 1) {
                ret = (ret + dfs(y + 1, x, v ^ grid[y + 1][x])) % mod;
            }

            if (x + 1 <= n - 1) {
                ret = (ret + dfs(y, x + 1, v ^ grid[y][x + 1])) % mod;
            }

            return cached[y][x][v] = ret;
        };

        return dfs(0, 0, grid[0][0]);
    }
};
// 380 ms
// 102.11 MB

class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 1e9 + 7;

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(16)));

        dp[0][0][grid[0][0]] = 1;
        for (int i = 1; i < m; ++i) {
            for (int v = 0; v < 16; ++v) {
                dp[i][0][v] = dp[i - 1][0][grid[i][0] ^ v];
            }
        }
        for (int j = 1; j < n; ++j) {
            for (int v = 0; v < 16; ++v) {
                dp[0][j][v] = dp[0][j - 1][grid[0][j] ^ v];
            }
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                for (int v = 0; v < 16; ++v) {
                    dp[i][j][v] = (dp[i][j][v] + dp[i - 1][j][grid[i][j] ^ v]) % mod;
                    dp[i][j][v] = (dp[i][j][v] + dp[i][j - 1][grid[i][j] ^ v]) % mod;
                }
            }
        }

        return dp[m - 1][n - 1][k];
    }
};
// 139 ms
// 101.60 MB

