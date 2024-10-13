class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans{0, INT_MAX};
        int k = nums.size();
        vector<int> indexes(k, 0);

        while (true) {
            int curMin = INT_MAX;
            int curMax = INT_MIN;
            int minListIndex = 0;

            for (int i = 0; i < k; ++i) {
                int curElement = nums[i][indexes[i]];

                if (curElement < curMin) {
                    curMin = curElement;
                    minListIndex = i;
                }

                if (curElement > curMax) {
                    curMax = curElement;
                }
            }

            if (curMax - curMin < ans[1] - ans[0]) {
                ans[0] = curMin;
                ans[1] = curMax;
            }

            if (++indexes[minListIndex] == nums[minListIndex].size()) {
                break;
            }
        }

        return ans;
    }
};
// 1091 ms
// 18.71 MB

