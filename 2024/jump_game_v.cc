class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n);

        function<int(int)> dfs = [&](int i) -> int {
            if (dp[i]) {
                return dp[i];
            }
            
            int ret = 1;
            for (int j = i - 1; j >= max(0, i - d) && arr[i] > arr[j]; --j) {
                ret = max(ret, 1 + dfs(j));
            }

            for (int j = i + 1; j <= min(n - 1, i + d) && arr[i] > arr[j]; ++j) {
                ret = max(ret, 1 + dfs(j));
            }

            return dp[i] = ret;
        };

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dfs(i));
        }

        return ans;
    }
};
// 44 ms
// 19 MB