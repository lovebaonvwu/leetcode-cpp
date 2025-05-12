class Solution
{
public:
    bool canPartitionGrid(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<long long> row_presum(m + 1);
        for (int i = 0; i < m; ++i)
        {
            long long sum = 0;
            for (int j = 0; j < n; ++j)
            {
                sum += grid[i][j];
            }

            row_presum[i + 1] = sum + row_presum[i];
        }

        for (int i = 1; i < m; ++i)
        {
            if (row_presum[i] - row_presum[0] == row_presum[m] - row_presum[i])
            {
                return true;
            }
        }

        vector<long long> col_presum(n + 1);
        for (int j = 0; j < n; ++j)
        {
            long long sum = 0;
            for (int i = 0; i < m; ++i)
            {
                sum += grid[i][j];
            }
            col_presum[j + 1] = sum + col_presum[j];
        }

        for (int j = 1; j < n; ++j)
        {
            if (col_presum[j] - col_presum[0] == col_presum[n] - col_presum[j])
            {
                return true;
            }
        }

        return false;
    }
};
// Time: O(m*n)
// Space: O(m+n)
// 3546. Equal Sum Grid Partition I