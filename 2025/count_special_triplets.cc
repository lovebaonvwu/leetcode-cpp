class Solution
{
public:
    int specialTriplets(vector<int> &nums)
    {
        unordered_map<int, long long> freq;
        for (auto n : nums)
        {
            ++freq[n];
        }

        unordered_map<int, long long> cnt;

        int ans = 0;
        int mod = 1e9 + 7;
        for (auto n : nums)
        {
            int target = 2 * n;

            if (cnt.find(target) != cnt.end())
            {
                ans = (ans + cnt[target] * (freq[target] - cnt[target] - (target == n))) % mod;
            }

            ++cnt[n];
        }

        return ans;
    }
};
// Time: O(n)
// Space: O(n)