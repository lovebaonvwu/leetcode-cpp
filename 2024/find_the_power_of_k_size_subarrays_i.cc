class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        for (int i = k - 1; i < n; ++i) {
            int power = nums[i];
            for (int j = 0; j < k - 1; ++j) {
                if (nums[i - j] != nums[i - j - 1] + 1) {
                    power = -1;
                    break;
                }
            }

            ans.push_back(power);
        }

        return ans;
    }
};
// 20 ms
// 33.25 MB
