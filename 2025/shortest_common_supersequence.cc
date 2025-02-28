class Solution {
    public:
        string shortestCommonSupersequence(string str1, string str2) {
            int m = str1.size();
            int n = str2.size();
    
            vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    
            for (int i = 1; i <= m; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (str1[i - 1] == str2[j - 1]) {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
    
            deque<char> ans;
            while (m || n) {
                char c;
                if (m == 0) {
                    c = str2[--n];
                } else if (n == 0) {
                    c = str1[--m];
                } else if (str1[m - 1] == str2[n - 1]) {
                    c = str1[--m] = str2[--n];
                } else if (dp[m][n] == dp[m - 1][n]) {
                    c = str1[--m];
                } else if (dp[m][n] == dp[m][n - 1]) {
                    c = str2[--n];
                }
    
                ans.push_front(c);
            }
    
            return {begin(ans), end(ans)};
        }
    };
    // 27 ms
    // 26.94 MB
