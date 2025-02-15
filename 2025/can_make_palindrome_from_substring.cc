class Solution {
    public:
        vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
            int n = s.size();
            vector<vector<int>> presum(n + 1, vector<int>(26));
    
            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j < 26; ++j) {
                    presum[i][j] = presum[i - 1][j];
                }
    
                ++presum[i][s[i - 1] - 'a'];
            }
    
            vector<bool> ans(queries.size());
    
            for (int i = 0; i < queries.size(); ++i) {
                int left = queries[i][0];
                int right = queries[i][1];
                int k = queries[i][2];
    
                int oddCount = 0;
                for (int j = 0; j < 26; ++j) {
                    if ((presum[right + 1][j] - presum[left][j]) % 2 != 0) {
                        ++oddCount;
                    }
                }
    
                if (2 * k >= oddCount - 1) {
                    ans[i] = true;
                } else {
                    ans[i] = false;
                }
            }
    
            return ans;
        }
};
// 115 ms
// 147.37 MB
