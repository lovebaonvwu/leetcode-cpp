class Solution
{
public:
    long long maxSubarrays(int n, vector<vector<int>> &conflictingPairs)
    {
        for (auto &p : conflictingPairs)
        {
            if (p[0] > p[1])
            {
                swap(p[0], p[1]);
            }
        }

        sort(begin(conflictingPairs), end(conflictingPairs), [](auto &a, auto &b)
             { return a[1] < b[1]; });

        int max1 = 0;
        int max2 = 0;
        long long occupied = 0;
        long long gain = 0;
        long long maxgain = 0;

        int m = conflictingPairs.size();

        for (int i = 0; i < m; ++i)
        {
            int start = conflictingPairs[i][0];
            int base = n + 1 - conflictingPairs[i][1];
            if (i < m - 1)
            {
                base = conflictingPairs[i + 1][1] - conflictingPairs[i][1];
            }

            if (start > max1)
            {
                max2 = max1;
                max1 = start;
                gain = 0;
            }
            else if (start > max2)
            {
                max2 = start;
            }

            occupied += 1LL * max1 * base;
            gain += 1LL * (max1 - max2) * base;

            maxgain = max(maxgain, gain);
        }

        long long total = 1LL * (n + 1) * n / 2;

        return total - occupied + maxgain;
    }
};
// Time: O(m log m), where m is the number of conflicting pairs
// Space: O(m)