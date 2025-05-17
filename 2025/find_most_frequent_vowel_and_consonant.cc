class Solution
{
public:
    int maxFreqSum(string s)
    {
        vector<int> cnt(26);

        for (auto ch : s)
        {
            ++cnt[ch - 'a'];
        }

        function<bool(const char)> isVowel = [](const char ch) -> bool
        {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        };

        int maxVowel = 0;
        int maxConst = 0;

        for (int i = 0; i < 26; ++i)
        {
            char ch = i + 'a';
            if (isVowel(ch))
            {
                if (cnt[i] > maxVowel)
                {
                    maxVowel = cnt[i];
                }
            }
            else
            {
                if (cnt[i] > maxConst)
                {
                    maxConst = cnt[i];
                }
            }
        }

        return maxVowel + maxConst;
    }
};
// Time: O(N)
// Space: O(1)
