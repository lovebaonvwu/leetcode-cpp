class Solution
{
public:
    string resultingString(string s)
    {
        stack<char> stk;

        for (auto ch : s)
        {
            if (!stk.empty() && ((stk.top() - 'a' + 1) % 26 == (ch - 'a') || (ch - 'a' + 1) % 26 == (stk.top() - 'a')))
            {
                stk.pop();
            }
            else
            {
                stk.push(ch);
            }
        }

        string ans;
        while (!stk.empty())
        {
            ans += stk.top();
            stk.pop();
        }

        reverse(begin(ans), end(ans));

        return ans;
    }
};
// Time: O(n)
// Space: O(n)