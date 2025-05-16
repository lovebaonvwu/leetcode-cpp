class Solution
{
public:
    vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups)
    {
        int n = words.size();
        unordered_map<int, vector<string>> mp;

        for (int i = 0; i < n; ++i)
        {
            mp[i].push_back(words[i]);
        }

        vector<vector<bool>> validDist(n, vector<bool>(n));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i != j && words[i].size() == words[j].size())
                {
                    int diff = 0;
                    for (int k = 0; k < words[i].size(); ++k)
                    {
                        if (words[i][k] != words[j][k])
                        {
                            ++diff;
                        }
                    }

                    validDist[i][j] = diff == 1;
                }
            }
        }

        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (groups[j] != groups[i] && validDist[i][j])
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        vector<string> tmp = mp[j];
                        tmp.push_back(words[i]);
                        mp[i] = tmp;
                    }
                }
            }
        }

        int maxIndex = -1;
        int maxValue = 0;

        for (int i = 0; i < n; ++i)
        {
            if (dp[i] > maxValue)
            {
                maxValue = dp[i];
                maxIndex = i;
            }
        }

        return mp[maxIndex];
    }
};
// Time: O(10 * n^2)
// Space: O(n^2)