class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 1; i <= 50; ++i) {
            int cur = 0;
            int maxCnt = 0;
            for (auto n : nums) {
                if (n == i) {
                    ++cur;
                }
                if (n == k) {
                    --cur;
                }

                if (cur < 0) {
                    cur = 0;
                }

                maxCnt = max(maxCnt, cur);
            }

            ans = max(ans, maxCnt);
        }
        return ans + count(begin(nums), end(nums), k);
    }
};
// 58 ms
// 96.47 MB

