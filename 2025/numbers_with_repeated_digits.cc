class Solution
{
    int ans = 0;

    int Arrangement(int n, int m)
    {
        int ret = 1;

        for (int i = 0; i < m; ++i)
        {
            ret *= (n - i);
        }

        return ret;
    }

    void dfs(const string &s, int i, vector<bool> &visited)
    {
        int len = s.size();

        if (i == len)
        {
            ans += 1;
            return;
        }

        for (int d = 0; d <= 9; ++d)
        {
            if (i == 0 && d == 0)
            {
                continue;
            }

            if (visited[d])
            {
                continue;
            }

            if (d < (s[i] - '0'))
            {
                ans += Arrangement(10 - (i + 1), len - (i + 1));
            }
            else if (d == (s[i] - '0'))
            {
                visited[d] = true;
                dfs(s, i + 1, visited);
                visited[d] = false;
            }
        }
    }

public:
    int numDupDigitsAtMostN(int n)
    {
        string s = to_string(n);
        for (int len = 1; len < s.size(); ++len)
        {
            ans += Arrangement(10, len) - Arrangement(9, len - 1);
        }

        vector<bool> visited(10);
        dfs(s, 0, visited);

        return n - ans;
    }
};
// Time: O(n)
// Space: O(1)
