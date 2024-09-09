class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int i = 0, j = 0;
        for (; j < n; ++j) {
            if (nums[j] > nums[i]) {
                ans += 1LL * (j - i) * nums[i];
                i = j;
            }
        }

        if (i < n - 1) {
            ans += 1LL * (j - 1 - i) * nums[i];
        }

        return ans;
    }
};
// 198 ms
// 171.46 MB
