class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans = 0;
        nums.push_back(INT_MIN);
        int n = nums.size();
        int prev = 0;
        int cur = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] <= nums[i - 1]) {
                if (prev > 0) {
                    ans = max(ans, min(prev, cur));
                }
                ans = max(ans, cur / 2);
                prev = cur;
                cur = 1;
            } else {
                ++cur;
            }
        }

        return ans;
    }
};
// 235 ms
// 172.78 MB