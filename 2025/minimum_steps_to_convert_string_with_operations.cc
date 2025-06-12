class Solution
{

    vector<int> cached;

    int matchOperations(const string &s, const string &t)
    {
        int cnt[26][26];
        memset(cnt, 0, sizeof(cnt));
        int ret = 0;

        int n = s.size();

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == t[i])
            {
                continue;
            }

            if (cnt[t[i] - 'a'][s[i] - 'a'] > 0)
            {
                --cnt[t[i] - 'a'][s[i] - 'a'];
            }
            else
            {
                ++cnt[s[i] - 'a'][t[i] - 'a'];
                ++ret;
            }
        }

        return ret;
    }

    int dfs(int i, const string &w1, const string &w2)
    {
        int n = w1.size();

        if (i == n)
        {
            return 0;
        }

        if (cached[i] != -1)
        {
            return cached[i];
        }

        int ret = INT_MAX;

        for (int j = i; j < n; ++j)
        {
            string s = w1.substr(i, j - i + 1);
            string t = w2.substr(i, j - i + 1);

            string r = t;
            reverse(r.begin(), r.end());

            int op1 = matchOperations(s, t);
            int op2 = matchOperations(s, r);

            ret = min(ret, min(op1, op2 + 1) + dfs(j + 1, w1, w2));
        }

        return cached[i] = ret;
    }

public:
    int minOperations(string word1, string word2)
    {
        cached.assign(word1.size(), -1);

        return dfs(0, word1, word2);
    }
};
// Time: O(n^3)
// Space: O(n)