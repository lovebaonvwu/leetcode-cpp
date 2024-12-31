class Solution {
    int cnt[1001][1001];
public:
    long long numberOfSubsequences(vector<int>& nums) {
        int n = nums.size();
        memset(cnt, 0, sizeof(cnt));

        long long ans = 0;
        for (int r = 4; r < n; ++r) {
            int q = r - 2;
            for (int p = 0; p < q - 1; ++p) {
                int g = gcd(nums[p], nums[q]);
                ++cnt[nums[p] / g][nums[q] / g];
            }

            for (int s = r + 2; s < n; ++s) {
                int g = gcd(nums[r], nums[s]);
                ans += cnt[nums[s] / g][nums[r] / g];
            }
        }

        return ans;
    }
};
// 215 ms
// 27.50 MB
