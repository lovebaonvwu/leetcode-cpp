class Solution {
    public:
        int maxCollectedFruits(vector<vector<int>>& fruits) {
            int n = fruits.size();
    
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                ans += fruits[i][i];
            }
    
            vector<vector<int>> cached2(n, vector<int>(n, -1));
            function<int(int, int)> dfs2 = [&](int i, int j) -> int {
                if (i == n - 1 && j == n - 1) {
                    return 0;
                }
    
                if (i >= j) {
                    return INT_MIN;
                }   
    
                if (cached2[i][j] != -1) {
                    return cached2[i][j];
                }
    
                int ret = 0;
                if (j - 1 >= 0) {
                    ret = max(ret, fruits[i][j] + dfs2(i + 1, j - 1));
                }
    
                if (j + 1 < n) {
                    ret = max(ret, fruits[i][j] + dfs2(i + 1, j + 1));
                }
    
                ret = max(ret, fruits[i][j] + dfs2(i + 1, j));
    
                return cached2[i][j] = ret;
            };
    
            vector<vector<int>> cached3(n, vector<int>(n, -1));
            function<int(int, int)> dfs3 = [&](int i, int j) -> int {
                if (i == n - 1 && j == n - 1) {
                    return 0;
                }
    
                if (i <= j) {
                    return INT_MIN;
                }   
    
                if (cached3[i][j] != -1) {
                    return cached3[i][j];
                }
    
                int ret = 0;
                if (i - 1 >= 0) {
                    ret = max(ret, fruits[i][j] + dfs3(i - 1, j + 1));
                }
    
                if (i + 1 < n) {
                    ret = max(ret, fruits[i][j] + dfs3(i + 1, j + 1));
                }
    
                ret = max(ret, fruits[i][j] + dfs3(i, j + 1));
    
                return cached3[i][j] = ret;
            };
    
            return ans + dfs2(0, n - 1) + dfs3(n - 1, 0);
        }
    };
    // Time: O(n^2)
    // Space: O(n^2)