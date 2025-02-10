class Solution {
public:
    int minMaxSums(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int mod = 1e9 + 7;
        int n = nums.size();
        vector<vector<long long>> comp(n + 1, vector<long long>(k + 1));

        for (int i = 0; i <= n; ++i) {
            comp[i][0] = 1;
            if (i == 0) {
                continue;
            }
            for (int j = 1; j <= min(n, k); ++j) {
                comp[i][j] = comp[i - 1][j - 1] + comp[i - 1][j];
                comp[i][j] %= mod;
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < min(i + 1, k); ++j) {
                ans += comp[i][j] * nums[i];
                ans %= mod;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < min(n - i, k); ++j) {
                ans += comp[n - 1 - i][j] * nums[i];
                ans %= mod;
            }
        }

        return ans;
    }
};
// 366 ms
// 272.50 MB