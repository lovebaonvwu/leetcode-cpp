class Solution
{
public:
    int numberOfPairs(vector<vector<int>> &points)
    {
        sort(begin(points), end(points), [](auto &a, auto &b)
             {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }

            return a[0] < b[0]; });

        int ans = 0;
        int n = points.size();

        for (int i = 0; i < n; ++i)
        {
            auto &p = points[i];
            int minX = p[0] - 1;
            int maxX = INT_MAX;
            int minY = INT_MIN;
            int maxY = p[1] + 1;

            for (int j = i + 1; j < n; ++j)
            {
                auto &q = points[j];
                int x = q[0];
                int y = q[1];
                if (x > minX && x < maxX && y > minY && y < maxY)
                {
                    ++ans;
                    minX = x;
                    minY = y;
                }
            }
        }

        return ans;
    }
};
// Time: O(n^2)
// Space: O(1)