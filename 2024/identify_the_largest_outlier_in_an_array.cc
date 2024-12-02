class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int total = 0;
        unordered_map<int, int> cnt;
        for (auto n : nums) {
            total += n;
            ++cnt[n];
        }

        int ans = INT_MIN;

        for (auto n : nums) {
            if ((total - n) % 2 != 0) {
                continue;
            }
            if (cnt.find((total - n) / 2) != cnt.end()) {
                if ((total - n) / 2 == n) {
                    if (cnt[n] > 1) {
                        ans = max(ans, n);
                    }
                } else {
                    ans = max(ans, n);
                }
            }
        }

        return ans;
    }
};
// 233 ms
// 181.55 MB