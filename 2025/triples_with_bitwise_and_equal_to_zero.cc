class Solution
{
public:
    int countTriplets(vector<int> &nums)
    {
        int n = 1 << 16;
        vector<vector<int>> dp(4, vector<int>(n));
        dp[0][n - 1] = 1;

        for (int i = 1; i < 4; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                for (auto a : nums)
                {
                    dp[i][j & a] += dp[i - 1][j];
                }
            }
        }

        return dp[3][0];
    }
};
// Time: O(n * 2^16)
// Space: O(2^16)

class Solution
{
public:
    int countTriplets(vector<int> &nums)
    {
        int n = 1 << 16;
        vector<int> dp(n);
        dp[n - 1] = 1;

        for (int i = 1; i < 4; ++i)
        {
            vector<int> tmp(n);
            for (int j = 0; j < n; ++j)
            {
                for (auto a : nums)
                {
                    tmp[j & a] += dp[j];
                }
            }
            swap(dp, tmp);
        }

        return dp[0];
    }
};
// Time: O(n * 2^16)
// Space: O(2^16)

class Solution
{
public:
    int countTriplets(vector<int> &nums)
    {
        unordered_map<int, int> cnt;
        for (auto a : nums)
        {
            for (auto b : nums)
            {
                ++cnt[a & b];
            }
        }

        int ans = 0;
        for (auto a : nums)
        {
            for (auto [k, v] : cnt)
            {
                if ((k & a) == 0)
                {
                    ans += v;
                }
            }
        }

        return ans;
    }
};
// Time: O(n^2)
// Space: O(n^2)
// n: number of elements in nums