class Solution
{
public:
    long long minimumDifference(vector<int> &nums)
    {
        int n = nums.size() / 3;
        long long sum = 0;
        priority_queue<long long> pl;

        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            pl.push(nums[i]);
        }

        vector<long long> psum(n + 1);
        psum[0] = sum;

        for (int i = n; i < 2 * n; ++i)
        {
            sum += nums[i];
            pl.push(nums[i]);
            sum -= pl.top();
            pl.pop();
            psum[i - (n - 1)] = sum;
        }

        priority_queue<long long, vector<long long>, greater<>> pr;
        sum = 0;
        for (int i = 3 * n - 1; i >= 2 * n; --i)
        {
            sum += nums[i];
            pr.push(nums[i]);
        }

        long long ans = psum[n] - sum;
        for (int i = 2 * n - 1; i >= n; --i)
        {
            sum += nums[i];
            pr.push(nums[i]);
            sum -= pr.top();
            pr.pop();

            ans = min(ans, psum[i - n] - sum);
        }

        return ans;
    }
};
// Time: O(n log n)
// Space: O(n)