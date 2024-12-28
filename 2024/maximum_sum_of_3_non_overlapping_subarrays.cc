class Solution {
    int dp(const vector<int>& sums, int k, int idx, int rem, vector<vector<int>>& memo) {
        if (rem == 0) {
            return 0;
        }

        if (idx >= sums.size()) {
            return rem > 0 ? INT_MIN : 0;
        }

        if (memo[idx][rem] != -1) {
            return memo[idx][rem];
        }

        int take = sums[idx] + dp(sums, k, idx + k, rem - 1, memo);
        int notake = dp(sums, k, idx + 1, rem, memo);

        memo[idx][rem] = max(take, notake);
        return memo[idx][rem];
    }

    void dfs(const vector<int>& sums, int k, int idx, int rem, vector<vector<int>>& memo, vector<int>& ans) {
        if (rem == 0) {
            return;
        }

        if (idx >= sums.size()) {
            return;
        }

        int take = sums[idx] + dp(sums, k, idx + k, rem - 1, memo);
        int notake = dp(sums, k, idx + 1, rem, memo);

        if (take >= notake) {
            ans.push_back(idx);
            dfs(sums, k, idx + k, rem - 1, memo, ans);
        } else {
            dfs(sums, k, idx + 1, rem, memo, ans);
        }
    }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size() - k + 1;
        vector<int> sums(n);

        for (int i = 0, sum = 0, j = 0; i < nums.size(); ++i) {
            sum += nums[i];

            if (i == k - 1) {
                sums[i - k + 1] = sum;
            }

            if (i > k - 1) {
                sum -= nums[i - k];
                sums[i - k + 1] = sum;
            }
        }

        vector<vector<int>> memo(n, vector<int>(4, -1));
        dp(sums, k, 0, 3, memo);

        vector<int> ans;
        dfs(sums, k, 0, 3, memo, ans);

        return ans;
    }
};
// 24 ms
// 34.92 MB

