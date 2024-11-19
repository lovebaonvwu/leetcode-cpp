class Solution {

    bool valid(const vector<int>& nums, const vector<int>& cnt) {
        for (int i = 0, sum = 0; i < nums.size(); ++i) {
            sum += cnt[i];
            if (nums[i] > sum) {
                return false;
            }
        }

        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int lo = 0;
        int hi = queries.size() - 1;

        long long total = accumulate(begin(nums), end(nums), 0LL);
        if (total == 0) {
            return 0;
        }

        while (lo < hi) {
            int md = (lo + hi) / 2;
            vector<int> cnt(n + 1);
            for (int i = 0; i <= md; ++i) {
                cnt[queries[i][0]] += queries[i][2];
                cnt[queries[i][1] + 1] -= queries[i][2];
            }

            bool result = valid(nums, cnt);

            if (result) {
                hi = md;
            } else {
                lo = md + 1;
            }
        }

        vector<int> cnt(n + 1);
        for (int i = 0; i <= lo; ++i) {
            cnt[queries[i][0]] += queries[i][2];
            cnt[queries[i][1] + 1] -= queries[i][2];
        }

        return valid(nums, cnt) ? lo + 1 : -1;
    }
};
// 70 ms
// 338.82 MB
