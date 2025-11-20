class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int>> &intervals)
    {
        sort(begin(intervals), end(intervals), [](auto &a, auto &b)
             {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }

            return a[0] < b[0]; });

        int n = intervals.size();
        int curMin = INT_MAX;
        int nextMin = INT_MAX;

        int ans = 0;

        for (int i = n - 1; i >= 0; --i)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if (end < curMin)
            {
                ans += 2;
                curMin = start;
                nextMin = start + 1;
            }
            else if (end < nextMin)
            {
                ans += 1;
                nextMin = curMin;
                curMin = start;
            }
        }

        return ans;
    }
};
// Time: O(n log n)
// Space: O(1)