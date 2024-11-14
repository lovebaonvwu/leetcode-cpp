class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;
        vector<long long> pow2(n, 1);
        for (int i = 1; i < n; ++i) {
            pow2[i] = (2 * pow2[i - 1]) % mod;
        }

        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (nums[i] * pow2[i]) % mod;
            ans -= (nums[i] * pow2[n - i - 1]) % mod;
            ans %= mod;
        }

        return ans;
    }
};
// 38 ms
// 62.08 MB
