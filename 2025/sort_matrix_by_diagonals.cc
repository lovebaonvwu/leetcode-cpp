class Solution
{
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                mp[i - j].push_back(grid[i][j]);
            }
        }

        for (auto &[k, v] : mp)
        {
            if (k >= 0)
            {
                sort(begin(v), end(v));
            }
            else
            {
                sort(rbegin(v), rend(v));
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                grid[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }

        return grid;
    }
};
// Time: O(n^2 log n)
// Space: O(n^2)