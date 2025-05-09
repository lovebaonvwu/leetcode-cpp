class Solution
{
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
        int n = s.size();

        if (i == n)
        {
            ans += 1;
            return;
        }

        for (int d = 0; d <= 9; ++d)
        {
            if (d == 0 && i == 0)
            {
                continue;
            }
            if (visited[d])
            {
                continue;
            }

            if (d < (s[i] - '0'))
            {
                ans += Arrangement(10 - (i + 1), n - (i + 1));
            }
            else if (d == (s[i] - '0'))
            {
                visited[d] = true;
                dfs(s, i + 1, visited);
                visited[d] = false;
            }
        }
    }

    int ans = 0;

public:
    int countSpecialNumbers(int n)
    {
        string s = to_string(n);

        for (int len = 1; len < s.size(); ++len)
        {
            ans += Arrangement(10, len) - Arrangement(9, len - 1);
        }

        vector<bool> visited(10);
        dfs(s, 0, visited);

        return ans;
    }
};
// Time: O(n)
// Space: O(1)
// n: number of digits in n