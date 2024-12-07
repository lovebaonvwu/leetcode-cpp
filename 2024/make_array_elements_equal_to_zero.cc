class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int total = accumulate(begin(nums), end(nums), 0);
        int n = nums.size();
        int ans = 0;
        for (int i = 0, sum = 0; i < n; ++i) {
            sum += nums[i];

            if (nums[i] == 0) {
                if (total % 2 == 0 && total - sum == total / 2) {
                    ans += 2;
                } else if (total % 2 == 1 && (total - sum == total / 2 || total - sum == total / 2 + 1)) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};
// 0 ms
// 22.00 MB
