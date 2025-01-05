class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int p = nums[i];
            int g = nums[i];
            int l = nums[i];
            for (int j = i + 1; j < n; ++j) {
                g = gcd(g, nums[j]);
                l = lcm(l, nums[j]);
                p *= nums[j];

                if (p == g * l) {
                    ans = max(ans, j - i + 1);
                } else {
                    break;
                }
            }
        }

        return ans;
    }
};
// 0 ms
// 27.82 MB

