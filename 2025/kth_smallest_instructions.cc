class Solution {
    public:
        string kthSmallestPath(vector<int>& destination, int k) {
            int m = destination[0] + 1;
            int n = destination[1] + 1;
    
            vector<vector<int>> dp(m, vector<int>(n));
            for (int i = 0; i < m; ++i) {
                dp[i][0] = 1;
            }
    
            for (int j = 0; j < n; ++j) {
                dp[0][j] = 1;
            }
    
            for (int i = 1; i < m; ++i) {
                for (int j = 1; j < n; ++j) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
    
            int row = destination[0];
            int col = destination[1];
    
            string ans;
            while (row && col) {
                if (dp[row][col - 1] >= k) {
                    ans += 'H';
                    --col;
                } else {
                    k -= dp[row][col - 1];
                    ans += 'V';
                    --row;
                }
            }
    
            while (row-- > 0) {
                ans += 'V';
            }
    
            while (col-- > 0) {
                ans += 'H';
            }
    
            return ans;
        }
    };
    // 0 ms
    // 19.02 MB
