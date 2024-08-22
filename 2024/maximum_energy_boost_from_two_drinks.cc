class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        dp[1][0] = energyDrinkA[0];
        dp[1][1] = energyDrinkB[0];

        for (int i = 2; i <= n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 2][1]) + energyDrinkA[i - 1];
            dp[i][1] = max(dp[i - 1][1], dp[i - 2][0]) + energyDrinkB[i - 1];
        }

        return max(dp[n][0], dp[n][1]);
    }
};
// 325 ms
// 256.30 MB
