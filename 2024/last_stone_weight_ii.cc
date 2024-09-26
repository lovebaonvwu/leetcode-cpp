class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(begin(stones), end(stones), 0);
        int target = total / 2;

        int n = stones.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= target; ++j) {
                if (stones[i - 1] > j) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i - 1]] + stones[i - 1]);
                }
            }
        }

        return total - (2 * dp[n][target]);
    }
};
// 6 ms
// 11.16 MB
