class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        int n = rains.size();
        vector<int> ans(n, 1);

        set<int> st;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; ++i)
        {
            if (rains[i] == 0)
            {
                st.insert(i);
            }
            else
            {
                ans[i] = -1;

                if (mp.count(rains[i]))
                {
                    auto it = st.lower_bound(mp[rains[i]]);
                    if (it == st.end())
                    {
                        ans = {};
                        break;
                    }

                    ans[*it] = rains[i];
                    st.erase(it);
                }

                mp[rains[i]] = i;
            }
        }

        return ans;
    }
};
// Time: O(n log n)
// Space: O(n)