class Solution
{
public:
    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {
        int n = fruits.size();

        vector<int> pos(n);
        vector<int> presum(n + 1);

        for (int i = 0; i < n; ++i)
        {
            pos[i] = fruits[i][0];
            presum[i + 1] = presum[i] + fruits[i][1];
        }

        int ans = 0;

        int start = lower_bound(begin(pos), end(pos), startPos) - begin(pos);

        for (int i = start; i < n; ++i)
        {
            if (pos[i] - startPos > k)
            {
                break;
            }

            double d = (k - (pos[i] - startPos)) / 2;
            int end = lower_bound(pos.begin(), pos.end(), startPos - d) - pos.begin();
            if (end >= 0 && end < n)
            {
                ans = max(ans, presum[i + 1] - presum[end]);
            }
        }

        start = upper_bound(begin(pos), end(pos), startPos) - begin(pos) - 1;
        for (int i = start; i >= 0; --i)
        {
            if (startPos - pos[i] > k)
            {
                break;
            }

            double d = (k - (startPos - pos[i])) / 2;
            int end = upper_bound(pos.begin(), pos.end(), startPos + d) - pos.begin() - 1;
            if (end >= 0 && end < n)
            {
                ans = max(ans, presum[end + 1] - presum[i]);
            }
        }

        return ans;
    }
};
// Time: O(n log n)
// Space: O(n)