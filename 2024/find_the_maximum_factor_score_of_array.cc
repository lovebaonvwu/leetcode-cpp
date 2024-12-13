class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        long long g = nums[0];
        long long l = nums[0];
        for (int i = 1; i < n; ++i) {
            g = gcd(g, nums[i]);
            l = lcm(l, nums[i]);
        }

        ans = max(ans, g * l);

        for (int i = 0; i < n; ++i) {
            long long g = 0;
            long long l = 0;
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }

                if (!g) {
                    g = nums[j];
                } else {
                    g = gcd(g, nums[j]);
                }

                if (!l) {
                    l = nums[j];
                } else {
                    l = lcm(l, nums[j]);
                }
            }

            ans = max(ans, g * l);
        }

        return ans;
    }
};
// 16 ms
// 25.94 MB
