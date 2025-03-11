class Solution {
    public:
        int cherryPickup(vector<vector<int>>& grid) {
            int n = grid.size();
            vector<vector<vector<int>>> cached(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
    
            function<int(int, int, int)> dfs = [&](int y1, int x1, int y2) -> int {
                int x2 = y1 + x1 - y2;
                if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0) {
                    return -1;
                }
    
                if (grid[y1][x1] == -1 || grid[y2][x2] == -1) {
                    return -1;
                }
    
                if (y1 == 0 && x1 == 0 && y2 == 0) {
                    return grid[y1][x1];
                }
    
                if (cached[y1][x1][y2] != INT_MIN) {
                    return cached[y1][x1][y2];
                }
    
                int ret = max({
                    dfs(y1 - 1, x1, y2 - 1), 
                    dfs(y1 - 1, x1, y2), 
                    dfs(y1, x1 - 1, y2 - 1), 
                    dfs(y1, x1 - 1, y2)});
    
                if (ret < 0) {
                    return cached[y1][x1][y2] = -1;
                }
    
                ret += grid[y1][x1];
                if (x1 != x2) {
                    ret += grid[y2][x2];
                }
    
                return cached[y1][x1][y2] = ret;
            };
    
            return max(0, dfs(n - 1, n - 1, n - 1));
        }
    };
    // 59 ms
    // 28.29 MB
