class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int ans = 0;
        for (int i = 0, prev = INT_MIN; i < nums.size(); ++i) {
            int min_n = nums[i] - k;
            int max_n = nums[i] + k;
            if (prev < min_n) {
                prev = min_n;
                ++ans;
            } else {
                if (prev + 1 <= max_n) {
                    prev = prev + 1;
                    ++ans;
                }
            }
        }

        return ans;
    }
};
// 134 ms
// 97.50 MB