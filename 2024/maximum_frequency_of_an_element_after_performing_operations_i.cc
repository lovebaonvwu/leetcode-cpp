class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> cnt;
        for (auto num : nums) {
            ++cnt[num];
        }

        sort(begin(nums), end(nums));
        int ans = 0;
        int left = 0;
        int right = 0;
        int n = nums.size();
        for (auto num : nums) {
            while (right < n && num + k >= nums[right]) {
                ++right;
            }

            while (left < n && num - k > nums[left]) {
                ++left;
            }

            int total = right - left;

            ans = max(ans, min(total - cnt[num], numOperations) + cnt[num]);
        }

        for (left = 0, right = 0; right < n; ++right) {
            int num = (nums[right] + nums[left]) / 2;
            while (num - nums[left] > k || num + k < nums[right]) {
                ++left;
                num = (nums[right] + nums[left]) / 2;
            }

            ans = max(ans, min(right - left + 1, numOperations));
        }

        return ans;
    }
};
// 203 ms
// 122.43 MB
