class Solution
{
    int minSum(const vector<vector<int>> &g, int u, int d, int l, int r)
    {
        int min_i = g.size();
        int max_i = 0;
        int min_j = g[0].size();
        int max_j = 0;

        for (int i = u; i <= d; ++i)
        {
            for (int j = l; j <= r; ++j)
            {
                if (g[i][j] == 1)
                {
                    min_i = min(min_i, i);
                    max_i = max(max_i, i);
                    min_j = min(min_j, j);
                    max_j = max(max_j, j);
                }
            }
        }

        return min_i <= max_i ? (max_i - min_i + 1) * (max_j - min_j + 1) : INT_MAX / 3;
    }
    vector<vector<int>> rotate(const vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ret(n, vector<int>(m));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ret[n - j - 1][i] = grid[i][j];
            }
        }

        return ret;
    }

    int solve(const vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        int res = m * n;
        for (int i = 0; i < m - 1; ++i)
        {
            for (int j = 0; j < n - 1; ++j)
            {
                res = min(res, minSum(grid, 0, i, 0, n - 1) +
                                   minSum(grid, i + 1, m - 1, 0, j) +
                                   minSum(grid, i + 1, m - 1, j + 1, n - 1));
                res = min(res, minSum(grid, 0, i, 0, j) +
                                   minSum(grid, 0, i, j + 1, n - 1) +
                                   minSum(grid, i + 1, m - 1, 0, n - 1));
            }
        }

        for (int i = 0; i < m - 2; ++i)
        {
            for (int j = i + 1; j < m - 1; ++j)
            {
                res = min(res, minSum(grid, 0, i, 0, n - 1) +
                                   minSum(grid, i + 1, j, 0, n - 1) +
                                   minSum(grid, j + 1, m - 1, 0, n - 1));
            }
        }

        return res;
    }

public:
    int minimumSum(vector<vector<int>> &grid)
    {
        auto rgrid = rotate(grid);

        return min(solve(grid), solve(rgrid));
    }
};
// Time: O(m^2 * n^2)
// Space: O(1)