class Solution
{
    long long count(int n)
    {
        long long power_of_4 = 1;

        long long cnt = 0;
        while (power_of_4 <= n)
        {
            cnt += (n - power_of_4 + 1);

            power_of_4 *= 4;
        }

        return cnt;
    }

public:
    long long minOperations(vector<vector<int>> &queries)
    {
        long long ans = 0;

        for (auto &q : queries)
        {
            long long steps = ((count(q[1]) - count(q[0] - 1)) + 1) / 2;
            ans += steps;
        }

        return ans;
    }
};
// Time: O(qlog(n))
// Space: O(1)