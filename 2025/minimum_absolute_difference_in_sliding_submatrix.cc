class Solution
{
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, INT_MAX));

        for (int r = 0; r < m - k + 1; ++r)
        {
            for (int c = 0; c < n - k + 1; ++c)
            {
                vector<int> tmp;
                for (int i = 0; i < k; ++i)
                {
                    for (int j = 0; j < k; ++j)
                    {
                        tmp.push_back(grid[r + i][c + j]);
                    }
                }

                sort(begin(tmp), end(tmp));
                for (int i = 0; i < tmp.size() - 1; ++i)
                {
                    if (tmp[i] != tmp[i + 1])
                    {
                        ans[r][c] = min(ans[r][c], abs(tmp[i] - tmp[i + 1]));
                    }
                }

                unordered_set<int> st(begin(tmp), end(tmp));
                if (st.size() == 1)
                {
                    ans[r][c] = 0;
                }
            }
        }

        return ans;
    }
};
// Time: O(m * n * k^2)
// Space: O(k^2) for the temporary storage of the submatrix elements
