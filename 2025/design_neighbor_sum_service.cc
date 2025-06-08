class NeighborSum
{
    vector<vector<int>> g;
    unordered_map<int, pair<int, int>> val_to_pos;
    int m;
    int n;
    int adj[5] = {-1, 0, 1, 0, -1};
    int diag[5] = {-1, -1, 1, 1, -1};

public:
    NeighborSum(vector<vector<int>> &grid)
    {
        g = grid;
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                val_to_pos[grid[i][j]] = {i, j};
            }
        }
    }

    int adjacentSum(int value)
    {
        int sum = 0;

        auto [y, x] = val_to_pos[value];

        for (int k = 0; k < 4; ++k)
        {
            int dy = y + adj[k];
            int dx = x + adj[k + 1];

            if (dy < 0 || dy == m || dx < 0 || dx == n)
            {
                continue;
            }

            sum += g[dy][dx];
        }

        return sum;
    }

    int diagonalSum(int value)
    {
        int sum = 0;

        auto [y, x] = val_to_pos[value];

        for (int k = 0; k < 4; ++k)
        {
            int dy = y + diag[k];
            int dx = x + diag[k + 1];

            if (dy < 0 || dy == m || dx < 0 || dx == n)
            {
                continue;
            }

            sum += g[dy][dx];
        }

        return sum;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
// Time: O(m * n)
// Space: O(m * n)