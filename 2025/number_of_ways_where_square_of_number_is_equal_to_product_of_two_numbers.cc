class Solution
{
public:
    int numTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        unordered_map<long long, int> st1;

        for (int i = 0; i < n1; ++i)
        {
            for (int j = i + 1; j < n1; ++j)
            {
                ++st1[1LL * nums1[i] * nums1[j]];
            }
        }

        int ans = 0;
        for (int i = 0; i < n2; ++i)
        {
            if (st1.find(1LL * nums2[i] * nums2[i]) != st1.end())
            {
                ans += st1[1LL * nums2[i] * nums2[i]];
            }
        }

        unordered_map<long long, int> st2;

        for (int i = 0; i < n2; ++i)
        {
            for (int j = i + 1; j < n2; ++j)
            {
                ++st2[1LL * nums2[i] * nums2[j]];
            }
        }

        for (int i = 0; i < n1; ++i)
        {
            if (st2.find(1LL * nums1[i] * nums1[i]) != st2.end())
            {
                ans += st2[1LL * nums1[i] * nums1[i]];
            }
        }

        return ans;
    }
};
// Time: O(n1^2 + n2^2)
// Space: O(n1^2 + n2^2)