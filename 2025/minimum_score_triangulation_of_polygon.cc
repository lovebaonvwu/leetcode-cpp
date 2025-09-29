class Solution
{
public:
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();

        vector<vector<int>> cached(n, vector<int>(n, -1));

        function<int(int, int)> dfs = [&](int i, int j) -> int
        {
            if (i + 2 > j)
            {
                return 0;
            }

            if (i + 2 == j)
            {
                return values[i] * values[i + 1] * values[j];
            }

            if (cached[i][j] != -1)
            {
                return cached[i][j];
            }

            int ret = INT_MAX;

            for (int k = i + 1; k < j; ++k)
            {
                ret = min(ret, values[i] * values[k] * values[j] + dfs(i, k) + dfs(k, j));
            }

            return cached[i][j] = ret;
        };

        return dfs(0, n - 1);
    }
};
// Time: O(n^3)
// Space: O(n^2)