class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans(n - k + 1, -1);

        for (int i = 0, j = 0; j < n; ++j) {
            if (j > 0 && nums[j] - nums[j - 1] != 1) {
                i = j;
            }

            if (j - i + 1 >= k) {
                ans[j - k + 1] = nums[j];
            }
        }

        return ans;
    }
};
// 193 ms
// 176.43 MB
