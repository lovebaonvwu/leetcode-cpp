class Solution
{
    long long getCost(int n, int k)
    {
        if (n <= k)
        {
            return 0;
        }
        return 1LL * (n - k) * k;
    }

public:
    long long minCuttingCost(int n, int m, int k)
    {

        return getCost(n, k) + getCost(m, k);
    }
};

// Time: O(1) for minCuttingCost
// Space: O(1) for storing the cost calculation