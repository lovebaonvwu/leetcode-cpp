class Solution {
    public:
        int longestPalindromicSubsequence(string s, int k) {
            int n = s.size();
            vector<vector<vector<int>>> cached(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
    
            function<int(int, int, int)> dfs = [&](int l, int r, int k) -> int {
                if (l > r) {
                    return 0;
                }
    
                if (l == r) {
                    return 1;
                }
    
                if (cached[l][r][k] != -1) {
                    return cached[l][r][k];
                }
    
                int ret = dfs(l + 1, r, k);
                ret = max(ret, dfs(l, r - 1, k));
    
                int cost = min(abs(s[l] - s[r]), 26 - abs(s[l] - s[r]));
                if (cost <= k) {
                    ret = max(ret, 2 + dfs(l + 1, r - 1, k - cost));
                }
    
                return cached[l][r][k] = ret;
            };
    
            return dfs(0, n - 1, k);
        }
    };
    // 836 ms
    // 241.71 MB
