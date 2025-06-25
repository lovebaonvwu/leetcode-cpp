class Solution
{
public:
    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
    {
        long long lo = -1e10;
        long long hi = 1e10;

        while (lo < hi)
        {
            long long md = lo + (hi - lo) / 2;

            long long cnt = countLessThanOrEqual(nums1, nums2, md);

            if (cnt < k)
            {
                lo = md + 1;
            }
            else
            {
                hi = md;
            }
        }

        return lo;
    }

    long long countLessThanOrEqual(vector<int> &nums1, vector<int> &nums2, long long md)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        long long ret = 0;

        for (int i = 0; i < n1; ++i)
        {
            if (nums1[i] > 0)
            {
                long long target = floor(1.0 * md / nums1[i]);
                auto it = upper_bound(begin(nums2), end(nums2), target);

                ret += (it - nums2.begin());
            }
            else if (nums1[i] == 0)
            {
                ret += (md >= 0 ? n2 : 0);
            }
            else
            {
                long long target = ceil(1.0 * md / nums1[i]);

                auto it = lower_bound(begin(nums2), end(nums2), target);

                ret += (n2 - (it - nums2.begin()));
            }
        }

        return ret;
    }
};
// Time: O(log 10^10 * n1 * log n2)
// Space: O(1)