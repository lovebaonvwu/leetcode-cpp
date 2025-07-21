class Solution
{
public:
    int countIslands(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        int dirs[] = {-1, 0, 1, 0, -1};

        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j])
                {
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    long long val = grid[i][j];
                    grid[i][j] = 0;

                    while (!q.empty())
                    {
                        auto [y, x] = q.front();
                        q.pop();

                        for (int k = 0; k < 4; ++k)
                        {
                            int dy = y + dirs[k];
                            int dx = x + dirs[k + 1];

                            if (dy < 0 || dy == m || dx < 0 || dx == n || grid[dy][dx] == 0)
                            {
                                continue;
                            }

                            val += grid[dy][dx];
                            grid[dy][dx] = 0;
                            q.push({dy, dx});
                        }
                    }

                    ans += (val >= k && (val % k == 0));
                }
            }
        }

        return ans;
    }
};
// Time: O(m * n)
// Space: O(m * n)