class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                ans[i] = nums[(i + nums[i]) % n];
            } else if (nums[i] < 0) {
                ans[i] = nums[(i + n - (abs(nums[i]) % n)) % n];
            } else {
                ans[i] = nums[i];
            }
        }

        return ans;
    }
};
// 8 ms
// 25.70 MB

