class Solution
{
    vector<bool> build(int n)
    {
        vector<bool> primes(n, true);
        primes[0] = false;
        primes[1] = false;

        for (int i = 2; i * i <= n; ++i)
        {
            if (primes[i])
            {
                for (int j = i * i; j <= n; j += i)
                {
                    primes[j] = false;
                }
            }
        }

        return primes;
    }

public:
    long long splitArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<bool> primes = build(n);

        long long a = 0;
        long long b = 0;

        for (int i = 0; i < n; ++i)
        {
            if (primes[i])
            {
                a += nums[i];
            }
            else
            {
                b += nums[i];
            }
        }

        return abs(a - b);
    }
};
// Time: O(n log log n)
// Space: O(n)