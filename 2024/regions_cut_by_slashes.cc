class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();

        vector<vector<int>> g(3 * n, vector<int>(3 * n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '/') {
                    int y = i * 3;
                    int x = j * 3;

                    g[y][x + 2] = 1;
                    g[y + 1][x + 1] = 1;
                    g[y + 2][x] = 1;
                } else if (grid[i][j] == '\\') {
                    int y = i * 3;
                    int x = j * 3;

                    g[y][x] = 1;
                    g[y + 1][x + 1] = 1;
                    g[y + 2][x + 2] = 1;
                }
            }
        }

        int ans = 0;
        int dirs[] = {-1, 0, 1, 0, -1};

        for (int i = 0; i < 3 * n; ++i) {
            for (int j = 0; j < 3 * n; ++j) {
                if (g[i][j] != 0) {
                    continue;
                }

                ++ans;
                queue<pair<int, int>> q;
                g[i][j] = ans;
                q.push({i, j});

                while (!q.empty()) {
                    auto [y, x] = q.front();
                    q.pop();

                    for (int k = 0; k < 4; ++k) {
                        int dy = y + dirs[k];
                        int dx = x + dirs[k + 1];

                        if (dy < 0 || dy == 3 * n || dx < 0 || dx == 3 * n) {
                            continue;
                        }

                        if (g[dy][dx] != 0) {
                            continue;
                        }

                        g[dy][dx] = ans;
                        q.push({dy, dx});
                    }
                }
            }
        }

        return ans;
    }
};
// 15 ms
// 18.52 MB
