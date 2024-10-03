class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total = accumulate(begin(nums), end(nums), 0LL);

        int target = total % p;
        if (target == 0) {
            return 0;
        }

        unordered_map<int, int> mp;
        mp[0] = -1;
        long long cur = 0;
        int ans = n;
        for (int i = 0; i < n; ++i) {
            cur = (cur + nums[i]) % p;
            int needed = (cur - target + p) % p;
            if (mp.find(needed) != mp.end()) {
                ans = min(ans, i - mp[needed]);
            }

            mp[cur] = i;
        }

        return ans == n ? -1 : ans;
    }
};
// 127 ms
// 70.31 MB
