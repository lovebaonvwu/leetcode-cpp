class Solution {
    bool isok(const vector<int>& nums, const vector<long long>& presum, long long k, int len) {
        int n = nums.size();
        for (long long i = 0; i + len - 1 < n; ++i) {
            long long j = i + len - 1;
            long long m = (i + j) / 2;

            long long leftsum = presum[m] - presum[i];
            long long rightsum = presum[j + 1] - presum[m + 1];

            if ((nums[m] * (m - i) - leftsum) + (rightsum - nums[m] * (j - m)) <= k) {
                return true;
            }
        }

        return false;
    }
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(begin(nums), end(nums));

        int n = nums.size();
        vector<long long> presum(n + 1);
        for (int i = 1; i <= n; ++i) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }

        int lo = 1;
        int hi = n;

        while (lo < hi) {
            int md = (lo + hi + 1) / 2;

            if (isok(nums, presum, k, md)) {
                lo = md;
            } else {
                hi = md - 1;
            }
        }

        return lo;
    }
};
// 39 ms
// 96.88 MB
