class Solution
{
public:
    string processStr(string s)
    {
        string ans = "";

        for (auto ch : s)
        {
            if (ch >= 'a' && ch <= 'z')
            {
                ans += ch;
            }
            else if (ch == '#')
            {
                ans += ans;
            }
            else if (ch == '%')
            {
                reverse(begin(ans), end(ans));
            }
            else if (ans.size() > 0 && ch == '*')
            {
                ans.pop_back();
            }
        }

        return ans;
    }
};
// Time: O(n)
// Space: O(n)