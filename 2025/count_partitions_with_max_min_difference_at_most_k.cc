class Solution
{
public:
    int countPartitions(vector<int> &nums, int k)
    {
        int n = nums.size();
        int mod = 1e9 + 7;

        vector<int> dp(n + 1);
        dp[0] = 1;

        int acc = 1;

        deque<int> maxq;
        deque<int> minq;

        for (int i = 0, j = 0; j < n; ++j)
        {
            while (!maxq.empty() && nums[j] > nums[maxq.back()])
            {
                maxq.pop_back();
            }
            maxq.push_back(j);

            while (!minq.empty() && nums[j] < nums[minq.back()])
            {
                minq.pop_back();
            }

            minq.push_back(j);

            while (i < j && nums[maxq.front()] - nums[minq.front()] > k)
            {
                acc = (acc - dp[i++] + mod) % mod;

                if (maxq.front() < i)
                {
                    maxq.pop_front();
                }
                if (minq.front() < i)
                {
                    minq.pop_front();
                }
            }

            dp[j + 1] = acc;
            acc = (acc + dp[j + 1]) % mod;
        }

        return dp[n];
    }
};

// Time: O(n)
// Space: O(n)