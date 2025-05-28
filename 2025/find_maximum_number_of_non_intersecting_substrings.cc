class Solution
{
public:
    int maxSubstrings(string word)
    {
        unordered_map<char, int> pos;
        int n = word.size();

        int ans = 0;

        for (int i = 0; i < n; ++i)
        {
            if (pos.find(word[i]) != pos.end())
            {
                if (i - pos[word[i]] + 1 >= 4)
                {
                    ++ans;
                    pos.clear();
                }
            }
            else
            {
                pos[word[i]] = i;
            }
        }

        return ans;
    }
};
// Time: O(n)
// Space: O(n)