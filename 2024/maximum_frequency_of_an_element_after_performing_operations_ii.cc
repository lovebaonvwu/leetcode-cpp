class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(begin(nums), end(nums));
        unordered_map<int, int> cnt;
        for (auto num : nums) {
            ++cnt[num];
        }

        int ans = 0;
        int n = nums.size();
        int left = 0;
        int right = 0;
        for (auto num : nums) {
            while (left < n && num - nums[left] > k) {
                ++left;
            }

            while (right < n && nums[right] - num <= k) {
                ++right;
            }

            int total = right - left;
            ans = max(ans, min(total - cnt[num], numOperations) + cnt[num]);
        }

        for (left = 0, right = 0; right < n; ++right) {
            int num = (nums[right] + nums[left]) / 2;
            while (nums[right] - num > k || num - nums[left] > k) {
                ++left;
                num = (nums[right] + nums[left]) / 2;
            }

            ans = max(ans, min(right - left + 1, numOperations));
        }

        return ans;
    }
};
// 185 ms
// 123.30 MB

