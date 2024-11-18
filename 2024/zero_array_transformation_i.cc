class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> cnt(n + 1);
        for (auto q : queries) {
            ++cnt[q[0]];
            --cnt[q[1] + 1];
        }

        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                cnt[i] += cnt[i - 1];
            }
            if (nums[i] > cnt[i]) {
                return false;
            }
        }

        return true;
    }
};
// 132 ms
// 324.76 MB
