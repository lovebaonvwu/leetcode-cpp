class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            mp[nums[i]] = i;
        }

        sort(begin(nums), end(nums));
        long long ans = n;
        for (int i = 1; i < n; ++i) {
            if (mp[nums[i]] < mp[nums[i - 1]]) {
                ans += n - i;
            }
        }

        return ans;
    }
};
// 230 ms
// 112.30 MB
