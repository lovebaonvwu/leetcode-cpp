class Solution
{
public:
    int countTrapezoids(vector<vector<int>> &points)
    {
        unordered_map<int, int> freq;
        int mod = 1e9 + 7;

        for (auto &point : points)
        {
            ++freq[point[1]];
        }

        vector<long long> cnt;
        for (auto [_, v] : freq)
        {
            cnt.push_back(v);
        }

        long long ans = 0;

        for (int i = 0, sum = 0; i < cnt.size(); ++i)
        {
            long long t = (cnt[i] - 1 + 1) * (cnt[i] - 1) / 2;
            ans += (t * sum);
            sum += t;
            ans %= mod;
        }

        return ans;
    }
};
// Time: O(n)
// Space: O(n)