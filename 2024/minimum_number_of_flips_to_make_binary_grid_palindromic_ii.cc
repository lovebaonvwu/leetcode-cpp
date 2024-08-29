class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;
        int single = 0;
        int pair = 0;

        for (int i = 0; i < m / 2; ++i) {
            for (int j = 0; j < n / 2; ++j) {
                int ones = grid[i][j] + grid[i][n - 1 - j] + grid[m - 1 - i][j] + grid[m - 1 - i][n - 1 - j];
                ans += min(ones, 4 - ones);
            }

            if (n % 2 == 1) {
                int ones = grid[i][n / 2] + grid[m - 1 - i][n / 2];
                single += ones == 1;
                pair += ones == 2;
            }
        }

        if (m % 2 == 1) {
            for (int j = 0; j < n / 2; ++j) {
                int ones = grid[m / 2][j] + grid[m / 2][n - 1 - j];
                single += ones == 1;
                pair += ones == 2;
            }

            if (n % 2 == 1) {
                ans += grid[m / 2][n / 2];
            }
        }

        if (pair % 2 == 0 || single > 0) {
            return ans + single;
        }

        return ans + 2;
    }
};
// 302 ms
// 193.68 MB
