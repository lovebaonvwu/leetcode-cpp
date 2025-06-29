class Solution
{
public:
    int maxSumDistinctTriplet(vector<int> &x, vector<int> &y)
    {
        int n = x.size();

        unordered_map<int, int> mp;

        for (int i = 0; i < n; ++i)
        {
            mp[x[i]] = max(mp[x[i]], y[i]);
        }

        vector<int> cand;
        for (auto [_, v] : mp)
        {
            cand.push_back(v);
        }

        if (cand.size() < 3)
        {
            return -1;
        }

        sort(rbegin(cand), rend(cand));

        return cand[0] + cand[1] + cand[2];
    }
};
// Time: O(n log n)
// Space: O(n)