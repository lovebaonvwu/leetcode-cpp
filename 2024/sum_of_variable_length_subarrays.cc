class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<int> presum(n + 1);
        
        for (int i = 1; i <= n; ++i) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int start = max(0, i - nums[i]);

            ans += presum[i + 1] - presum[start];
        }

        return ans;
    }
};
// 0 ms
// 27.38 MB
