class Solution {
    int m;
    int n;

    int totalIsland(vector<vector<int>> g) {
        int dirs[] = {-1, 0, 1, 0, -1};
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] == 1) {
                    ++count;

                    queue<pair<int, int>> q;
                    q.push({i, j});
                    g[i][j] = 0;

                    while (!q.empty()) {
                        auto [y, x] = q.front();
                        q.pop();

                        for (int k = 0; k < 4; ++k) {
                            int dy = y + dirs[k];
                            int dx = x + dirs[k + 1];

                            if (dy < 0 || dy == m || dx < 0 || dx == n) {
                                continue;
                            }

                            if (g[dy][dx] == 0) {
                                continue;
                            }

                            q.push({dy, dx});
                            g[dy][dx] = 0;
                        }
                    }
                }
            }
        }

        return count;
    }
public:
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int count = totalIsland(grid);
        if (count > 1 || count == 0) {
            return 0;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;

                    int count = totalIsland(grid);
                    if (count > 1 || count == 0) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};
// 84 ms
// 41.32 MB