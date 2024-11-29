class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({0, 0, 0});
        dist[0][0] = true;

        int dirs[] = {-1, 0, 1, 0, -1};
        while (!pq.empty()) {
            auto [curTime, y, x] = pq.top();
            pq.pop();

            if (y == m - 1 && x == n - 1) {
                return curTime;
            }

            for (int k = 0; k < 4; ++k) {
                int dy = y + dirs[k];
                int dx = x + dirs[k + 1];

                if (dy < 0 || dy == m || dx < 0 || dx == n) {
                    continue;
                }

                if (curTime + 1 < grid[dy][dx]) {
                    if ((grid[dy][dx] - curTime) % 2 == 0) {
                        if (grid[dy][dx] + 1 < dist[dy][dx]) {
                            dist[dy][dx] = grid[dy][dx] + 1;
                            pq.push({grid[dy][dx] + 1, dy, dx});
                        }
                    } else {
                        if (grid[dy][dx] + 1 < dist[dy][dx]) {
                            dist[dy][dx] = grid[dy][dx];
                            pq.push({grid[dy][dx], dy, dx});
                        }
                    }
                } else if (curTime + 1 < dist[dy][dx]) {
                    dist[dy][dx] = curTime + 1;
                    pq.push({curTime + 1, dy, dx});
                }
            }
        }

        return -1;
    }
};
// 213 ms
// 56.64 MB