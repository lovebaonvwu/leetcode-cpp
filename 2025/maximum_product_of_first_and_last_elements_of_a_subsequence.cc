class Solution
{
public:
    long long maximumProduct(vector<int> &nums, int m)
    {
        long long ans = LONG_MIN;

        int n = nums.size();

        vector<vector<long long>> minmax(n, vector<long long>(2));

        for (int i = 0; i < n; ++i)
        {
            minmax[i][0] = max(1LL * nums[i], i > 0 ? minmax[i - 1][0] : LONG_MIN);
            minmax[i][1] = min(1LL * nums[i], i > 0 ? minmax[i - 1][1] : LONG_MAX);

            if (i >= m - 1)
            {
                ans = max(ans, max(nums[i] * minmax[i - m + 1][0], nums[i] * minmax[i - m + 1][1]));
            }
        }

        return ans;
    }
};
// Time: O(n)
// Space: O(n)