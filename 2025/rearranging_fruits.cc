class Solution
{
public:
    long long minCost(vector<int> &basket1, vector<int> &basket2)
    {
        unordered_map<int, int> mp;
        int globalMin = INT_MAX;
        for (auto b : basket1)
        {
            ++mp[b];
            globalMin = min(globalMin, b);
        }

        for (auto b : basket2)
        {
            --mp[b];
            globalMin = min(globalMin, b);
        }

        vector<int> cnt;
        for (auto &[k, v] : mp)
        {
            if (v % 2 != 0)
            {
                return -1;
            }

            for (int i = 0; i < abs(v) / 2; ++i)
            {
                cnt.push_back(k);
            }
        }

        sort(begin(cnt), end(cnt));

        long long ans = 0;

        for (int i = 0; i < cnt.size() / 2; ++i)
        {
            ans += min(cnt[i], 2 * globalMin);
        }

        return ans;
    }
};
// Time: O(n log n)
// Space: O(n)