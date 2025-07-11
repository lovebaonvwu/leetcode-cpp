class Solution
{
    int cached[7001][2];
    unordered_map<int, int> f;

    int dfs(int cur, int headedLeft, int a, int b, int x)
    {
        if (cur == x)
        {
            return 0;
        }

        if (cur < 0 || f.find(cur) != f.end() || cur > 6000)
        {
            return INT_MAX / 2;
        }

        if (cached[cur][headedLeft] != -1)
        {
            return cached[cur][headedLeft];
        }

        int ret = INT_MAX / 2;

        cached[cur][headedLeft] = 1 + dfs(cur + a, 0, a, b, x);
        if (!headedLeft)
        {
            cached[cur][headedLeft] = min(cached[cur][headedLeft], 1 + dfs(cur - b, 1, a, b, x));
        }

        return cached[cur][headedLeft];
    }

public:
    int minimumJumps(vector<int> &forbidden, int a, int b, int x)
    {
        memset(cached, -1, sizeof(cached));
        for (int i = 0; i < forbidden.size(); ++i)
            f[forbidden[i]] = 1;

        int ans = dfs(0, 0, a, b, x);

        return ans > INT_MAX / 2 ? -1 : ans;
    }
};
// Time: O(n * a * b)
// Space: O(7001 * 2)