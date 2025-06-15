class Solution
{
public:
    string generateTag(string caption)
    {
        string ans = "#";

        stringstream ss(caption);

        string s;

        while (ss >> s)
        {
            if (ans.size() == 1)
            {
                if (isupper(s[0]))
                {
                    s[0] = s[0] - 'A' + 'a';
                }
            }
            else
            {
                if (islower(s[0]))
                {
                    s[0] = s[0] - 'a' + 'A';
                }
            }
            for (int i = 1; i < s.size(); ++i)
            {
                if (isupper(s[i]))
                {
                    s[i] = s[i] - 'A' + 'a';
                }
            }
            ans += s;
        }

        return ans.substr(0, min((int)ans.size(), 100));
    }
};
// Time: O(n)
// Space: O(1)