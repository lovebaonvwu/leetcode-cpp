class Solution
{
    string ans;
    string s;
    int k;

    bool check(const string &t)
    {
        for (int i = 0, j = 0; i < s.size(); ++i)
        {
            if (s[i] != t[j % t.size()])
            {
                continue;
            }

            ++j;
            if (j % t.size() == 0 && j / t.size() == k)
            {
                return true;
            }
        }

        return false;
    }

    void dfs(const string &t, string &tmp)
    {
        if (tmp != "" && !check(tmp))
        {
            return;
        }

        if (tmp.size() > ans.size() || (tmp.size() == ans.size() && tmp > ans))
        {
            ans = tmp;
        }

        if (tmp.size() == 7)
        {
            return;
        }

        for (auto ch : t)
        {
            tmp.push_back(ch);
            dfs(t, tmp);
            tmp.pop_back();
        }
    }

public:
    string longestSubsequenceRepeatedK(string s, int k)
    {
        this->s = s;
        this->k = k;

        vector<int> cnt(26);

        for (auto ch : s)
        {
            ++cnt[ch - 'a'];
        }

        string t;
        for (int i = 0; i < 26; ++i)
        {
            if (cnt[i] >= k)
            {
                t.push_back(i + 'a');
            }
        }

        string tmp;
        dfs(t, tmp);

        return ans;
    }
};
// Time: O(2^7 * 7 * n)
// Space: O(1) for the string ans, O(n) for the input string s