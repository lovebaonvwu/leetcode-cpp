class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            ans = max(ans, abs(nums[i] - nums[(i + 1) % n]));
        }

        return ans;
    }
};
// 0 ms
// 30.36 MB
