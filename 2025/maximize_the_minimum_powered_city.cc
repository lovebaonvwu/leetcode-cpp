class Solution
{

    bool check(vector<long long> diff, long long target, int k, int r, int n)
    {
        long long sum = 0;

        for (int i = 0; i < n; ++i)
        {
            sum += diff[i];

            if (sum < target)
            {
                long long add = target - sum;
                if (k < add)
                {
                    return false;
                }

                k -= add;
                sum += add;

                int right = min(n, i + 2 * r + 1);
                diff[right] -= add;
            }
        }

        return true;
    }

public:
    long long maxPower(vector<int> &stations, int r, int k)
    {
        int n = stations.size();

        vector<long long> cnt(n + 1);

        for (int i = 0; i < n; ++i)
        {
            int left = max(0, i - r);
            int right = min(n, i + r + 1);

            cnt[left] += stations[i];
            cnt[right] -= stations[i];
        }

        long long lo = *min_element(begin(stations), end(stations));
        long long hi = accumulate(begin(stations), end(stations), 0LL) + k;

        while (lo < hi)
        {
            long long md = (lo + hi + 1) / 2;

            if (check(cnt, md, k, r, n))
            {
                lo = md;
            }
            else
            {
                hi = md - 1;
            }
        }

        return lo;
    }
};
// Time: O(n log m), where n is the number of cities and m is the maximum possible power level.
// Space: O(n), to store the difference array.