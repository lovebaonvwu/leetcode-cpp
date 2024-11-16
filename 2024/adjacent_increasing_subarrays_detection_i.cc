class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for (int i = 0; i <= n - 2 * k; ++i) {
            int cnt = 0;
            for (int j = i + 1; j < i + k; ++j) {
                if (nums[j] <= nums[j - 1]) {
                    ++cnt;
                }
            }

            for (int j = i + k + 1; j < i + 2 * k; ++j) {
                if (nums[j] <= nums[j - 1]) {
                    ++cnt;
                }
            }

            if (cnt == 0) {
                return true;
            }
        }

        return false;
    }
};
// 12 ms
// 39.91 MB