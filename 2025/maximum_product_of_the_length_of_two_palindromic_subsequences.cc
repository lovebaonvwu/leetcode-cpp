class Solution
{
    bool isPalindrom(const string &s)
    {
        int i = 0;
        int j = s.size() - 1;

        while (i < j)
        {
            if (s[i++] != s[j--])
            {
                return false;
            }
        }

        return true;
    }

    void dfs(int i, const string &s, string &a, string &b)
    {
        int n = s.size();
        if (i == n)
        {
            if (isPalindrom(a) && isPalindrom(b))
            {
                ans = max(ans, (int)(a.size() * b.size()));
            }

            return;
        }

        for (int j = i; j < n; ++j)
        {
            a.push_back(s[j]);
            dfs(j + 1, s, a, b);
            a.pop_back();

            b.push_back(s[j]);
            dfs(j + 1, s, a, b);
            b.pop_back();

            dfs(j + 1, s, a, b);
        }
    }

    int ans = 0;

public:
    int maxProduct(string s)
    {
        string a;
        string b;
        dfs(0, s, a, b);

        return ans;
    }
};
// Time: O(3^n)
// Space: O(n)

class Solution
{
    bool isPalindrom(const string &s)
    {
        int i = 0;
        int j = s.size() - 1;

        while (i < j)
        {
            if (s[i++] != s[j--])
            {
                return false;
            }
        }

        return true;
    }

    void dfs(int i, const string &s, string &a, string &b)
    {
        int n = s.size();
        if (i == n)
        {
            if (isPalindrom(a) && isPalindrom(b))
            {
                ans = max(ans, (int)(a.size() * b.size()));
            }

            return;
        }

        a.push_back(s[i]);
        dfs(i + 1, s, a, b);
        a.pop_back();

        b.push_back(s[i]);
        dfs(i + 1, s, a, b);
        b.pop_back();

        dfs(i + 1, s, a, b);
    }

    int ans = 0;

public:
    int maxProduct(string s)
    {
        string a;
        string b;
        dfs(0, s, a, b);

        return ans;
    }
};
// Time: O(3^n)
// Space: O(n)