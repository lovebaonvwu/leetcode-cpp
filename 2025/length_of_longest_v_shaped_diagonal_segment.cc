class Solution {
    public:
        int lenOfVDiagonal(vector<vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
    
            int dirs[] = {1, 1, -1, -1, 1, 1};
    
            int cached[501][501][5][2] = {0};
            memset(cached, -1, sizeof(cached));
    
            function<int(int, int, int, int)> dfs = [&](int y, int x, int k, int c) -> int {
                if (cached[y][x][k][c] != -1) {
                    return cached[y][x][k][c];
                }
    
                int dy = y + dirs[k];
                int dx = x + dirs[k + 1];
    
                if (dy < 0 || dy == m || dx < 0 || dx == n) {
                    return 1;
                }
    
                if (grid[y][x] == 2 && grid[dy][dx] != 0) {
                    return 1;
                }
    
                if (grid[y][x] == 0 && grid[dy][dx] != 2) {
                    return 1;
                }
    
                if (grid[y][x] == 1 && grid[dy][dx] != 2) {
                    return 1;
                }
    
                int ret = 0;
                ret = max(ret, 1 + dfs(dy, dx, k, c));
    
                if (c > 0) {
                    ret = max(ret, 1 + dfs(dy, dx, k + 1, c - 1));
                }
    
                return cached[y][x][k][c] = ret;
            };
    
            int ans = 0;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == 1) {
                        for (int k = 0; k < 4; ++k) {
                            ans = max(ans, dfs(i, j, k, 1));
                        }
                    }
                }
            }
    
            return ans;
        }
    };
    // 475 ms
    // 105.52 MB