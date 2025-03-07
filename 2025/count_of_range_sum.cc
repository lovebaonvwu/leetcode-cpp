class Solution {
    int ans = 0;
    int temp[100001];

    void dfs(vector<long long>& presum, int lo, int hi, int lower, int upper) {
        if (lo >= hi) {
            return;
        }

        int md = lo + (hi - lo) / 2;
        dfs(presum, lo, md, lower, upper);
        dfs(presum, md + 1, hi, lower, upper);

        for (int i = lo; i <= md; ++i) {
            auto l = lower_bound(presum.begin() + md + 1, presum.begin() + hi + 1, presum[i] + lower);
            auto r = upper_bound(presum.begin() + md + 1, presum.begin() + hi + 1, presum[i] + upper);

            ans += r - l;
        }

        inplace_merge(presum.begin()+lo, presum.begin()+md+1, presum.begin()+hi+1);
    }
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> presum(n + 1);
        for (int i = 1; i <= n; ++i) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }

        dfs(presum, 0, n, lower, upper);

        return ans;
    }
};
// 439 ms
// 170.04 MB
