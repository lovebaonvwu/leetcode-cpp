class Solution 
{
public:
    int deleteGreatestValue(vector<vector<int>>& grid) 
    {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (auto& g : grid)
        {
            sort(g.rbegin(), g.rend());
        }

        for (int j = 0; j < n; ++j)
        {
            int val = 0;
            for (int i = 0; i < m; ++i)
            {
                val = max(val, grid[i][j]);
            }

            ans += val;
        }

        return ans;
    }
};
// Runtime 12 ms
// Memory 9.5 MB
// 2022.12.24 at 茗筑美嘉