class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        priority_queue<array<int, 3>> pq;
        pq.push({health - grid[0][0], 0, 0});

        vector<vector<int>> dist(m, vector<int>(n));

        int dirs[] = {-1, 0, 1, 0, -1};

        while (!pq.empty()) {
            auto [cur, y, x] = pq.top();
            pq.pop();

            if (y == m - 1 && x == n - 1) {
                return true;
            }

            for (int k = 0; k < 4; ++k) {
                int dy = y + dirs[k];
                int dx = x + dirs[k + 1];

                if (dy < 0 || dy == m || dx < 0 || dx == n) {
                    continue;
                }

                if (cur - grid[dy][dx] > dist[dy][dx]) {
                    dist[dy][dx] = cur - grid[dy][dx];
                    pq.push({cur - grid[dy][dx], dy, dx});
                }
            }
        }

        return false;
    }
};
// 40 ms
// 30.44 MB
