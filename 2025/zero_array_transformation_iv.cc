class Solution {
    bool dp[10][1001];
    bool isOK(const vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (!dp[i][nums[i]]) {
                return false;
            }
        }

        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        for (int i = 0; i < 10; ++i) {
            dp[i][0] = true;
        }

        if (isOK(nums)) {
            return 0;
        }

        for (int k = 0; k < queries.size(); ++k) {
            int left = queries[k][0];
            int right = queries[k][1];
            int val = queries[k][2];

            for (int i = left; i <= right; ++i) {
                for (int j = 1000; j >= 0; --j) {
                    if (j >= val && dp[i][j - val]) {
                        dp[i][j] = true;
                    }
                }
            }

            if (isOK(nums)) {
                return k + 1;
            }
        }

        return -1;
    }
};
// Time: O(Q*10*N)
// Space: O(10*N)
