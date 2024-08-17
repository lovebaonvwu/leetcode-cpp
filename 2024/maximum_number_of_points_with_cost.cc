class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();

        vector<vector<long long>> dp(m, vector<long long>(n));
        for (int j = 0; j < n; ++j) {
            dp[0][j] = points[0][j];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    dp[i][j] = max(dp[i][j], points[i][j] + dp[i - 1][k] - abs(k - j));
                }
            }
        }

        return *max_element(begin(dp[m - 1]), end(dp[m - 1]));
    }
};
// Time Limit Exceeded

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size();
        int n = points[0].size();

        vector<vector<long long>> dp(m, vector<long long>(n));
        for (int j = 0; j < n; ++j) {
            dp[0][j] = points[0][j];
        }

        for (int i = 1; i < m; ++i) {
            vector<long long> leftMax(n);
            leftMax[0] = dp[i - 1][0];
            for (int j = 1; j < n; ++j) {
                leftMax[j] = max(leftMax[j - 1] - 1, dp[i - 1][j]);
            }

            vector<long long> rightMax(n);
            rightMax[n - 1] = dp[i - 1][n - 1];
            for (int j = n - 2; j >= 0; --j) {
                rightMax[j] = max(rightMax[j + 1] - 1, dp[i - 1][j]);
            }

            for (int j = 0; j < n; ++j) {
                dp[i][j] = points[i][j] + max(leftMax[j], rightMax[j]);
            }
        }

        return *max_element(begin(dp[m - 1]), end(dp[m - 1]));
    }
};
// 224 ms
// 133.41 MB