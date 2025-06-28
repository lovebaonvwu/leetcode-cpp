class Solution
{
public:
    string makeSmallestPalindrome(string s)
    {
        int i = 0;
        int j = s.size() - 1;

        while (i < j)
        {
            if (s[i] < s[j])
            {
                s[j] = s[i];
            }
            else
            {
                s[i] = s[j];
            }

            ++i, --j;
        }

        return s;
    }
};
// Time: O(n)
// Space: O(1) for the string s, O(n) for the input string