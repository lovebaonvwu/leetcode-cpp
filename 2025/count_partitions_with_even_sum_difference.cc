class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total = accumulate(begin(nums), end(nums), 0);

        int ans = 0;
        for (int i = 0, sum = 0; i < nums.size() - 1; ++i) {
            sum += nums[i];
            total -= nums[i];

            if (abs(sum - total) % 2 == 0) {
                ++ans;
            }
        }

        return ans;
    }
};
// 0 ms
// 22.53 MB
