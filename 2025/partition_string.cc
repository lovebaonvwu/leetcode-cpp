class Solution
{
public:
    vector<string> partitionString(string s)
    {
        unordered_set<string> st;

        vector<string> ans;

        string t;
        for (int i = 0; i < s.size(); ++i)
        {
            t += s[i];

            if (st.find(t) == st.end())
            {
                st.insert(t);
                ans.push_back(t);
                t = "";
            }
        }

        return ans;
    }
};
// Time: O(n)
// Space: O(n)