class Solution
{
    int n;
    int dfs(const vector<int> &nums, vector<vector<int>> &cached, int i, int k)
    {
        if (i == n)
        {
            return k == 0 ? 0 : INT_MAX;
        }

        if (k == 0)
        {
            return INT_MAX;
        }

        if (cached[i][k] != -1)
        {
            return cached[i][k];
        }

        int ret = INT_MAX;

        int cur = 0;
        for (int j = i; j < n; ++j)
        {
            cur ^= nums[j];
            ret = min(ret, max(cur, dfs(nums, cached, j + 1, k - 1)));
        }

        return cached[i][k] = ret;
    }

public:
    int minXor(vector<int> &nums, int k)
    {
        n = nums.size();

        vector<vector<int>> cached(n, vector<int>(k + 1, -1));

        return dfs(nums, cached, 0, k);
    }
};
// Time: O(n^2 * k)
// Space: O(n * k)