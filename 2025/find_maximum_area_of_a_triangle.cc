class Solution
{
public:
    long long maxArea(vector<vector<int>> &coords)
    {
        unordered_map<int, pair<int, int>> baseX;
        unordered_map<int, pair<int, int>> baseY;

        int largestX = 0, smallestX = INT_MAX;
        int largestY = 0, smallestY = INT_MAX;
        ;

        for (auto &c : coords)
        {
            int x = c[0];
            int y = c[1];

            if (baseY.find(x) == baseY.end())
            {
                baseY[x] = {y, y};
            }
            else
            {
                baseY[x].first = min(y, baseY[x].first);
                baseY[x].second = max(y, baseY[x].second);
            }

            if (baseX.find(y) == baseX.end())
            {
                baseX[y] = {x, x};
            }
            else
            {
                baseX[y].first = min(x, baseX[y].first);
                baseX[y].second = max(x, baseX[y].second);
            }

            largestX = max(largestX, x);
            smallestX = min(smallestX, x);
            largestY = max(largestY, y);
            smallestY = min(smallestY, y);
        }

        long long ans = -1;

        for (auto &[x, yy] : baseY)
        {
            long long base = yy.second - yy.first;
            if (base > 0 && x != largestX)
            {
                ans = max(ans, base * (largestX - x));
            }

            if (base > 0 && x != smallestX)
            {
                ans = max(ans, base * (x - smallestX));
            }
        }

        for (auto &[y, xx] : baseX)
        {
            long long base = xx.second - xx.first;
            if (base > 0 && y != largestY)
            {
                ans = max(ans, base * (largestY - y));
            }

            if (base > 0 && y != smallestY)
            {
                ans = max(ans, base * (y - smallestY));
            }
        }

        return ans;
    }
};

// Time: O(n)
// Space: O(n)