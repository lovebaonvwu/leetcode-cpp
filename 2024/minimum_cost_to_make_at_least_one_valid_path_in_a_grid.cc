class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> maxCost(m, vector<int>(n, INT_MAX));

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({0, 0, 0});
        maxCost[0][0] = 0;

        vector<pair<int, int>> dirs = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!pq.empty()) {
            auto [cost, y, x] = pq.top();
            pq.pop();

            if (y == m - 1 && x == n - 1) {
                return cost;
            }

            for (int k = 1; k <= 4; ++k) {
                int dy = y + dirs[k].first;
                int dx = x + dirs[k].second;

                if (dy < 0 || dy == m || dx < 0 || dx == n) {
                    continue;
                }

                int newCost = cost + (grid[y][x] != k);
                if (newCost < maxCost[dy][dx]) {
                    maxCost[dy][dx] = newCost;
                    pq.push({newCost, dy, dx});
                }
            }
        }

        return -1;
    }
};
// 37 ms
// 19.38 MB
