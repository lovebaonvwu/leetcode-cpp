class Solution
{
    int commonPrefixLength(const string &a, const string &b)
    {
        int ret = 0;

        for (int i = 0, j = 0; i < a.size() && j < b.size(); ++i, ++j)
        {
            if (a[i] != b[j])
            {
                break;
            }

            ++ret;
        }

        return ret;
    }

public:
    vector<int> longestCommonPrefix(vector<string> &words)
    {
        int n = words.size();

        vector<int> commonPrefix(n);
        for (int i = 1; i < n; ++i)
        {
            commonPrefix[i] = commonPrefixLength(words[i - 1], words[i]);
        }

        vector<int> prefix(n);
        for (int i = 1; i < n; ++i)
        {
            prefix[i] = max(prefix[i - 1], commonPrefix[i]);
        }

        vector<int> suffix(n);
        for (int i = n - 2; i >= 0; --i)
        {
            suffix[i] = max(suffix[i + 1], commonPrefix[i + 1]);
        }

        vector<int> ans;

        for (int i = 0; i < n; ++i)
        {
            int best = 0;
            best = (i > 0 ? max(best, prefix[i - 1]) : 0);
            best = max(best, (i < n - 1 ? suffix[i + 1] : 0));
            if (i > 0 && i < n - 1)
            {
                best = max(best, commonPrefixLength(words[i - 1], words[i + 1]));
            }

            ans.push_back(best);
        }

        return ans;
    }
};
// Time: O(n * m), where n is the number of words and m is the average length of the words
// Space: O(n)