class Solution {
public:
    int numOfWays(int n) {
        long long colors2 = 6;
        long long colors3 = 6;

        int mod = 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            long long tmp2 = colors2;
            long long tmp3 = colors3;
            colors2 = ((3 * tmp2) % mod + (2 * tmp3) % mod) % mod;
            colors3 = ((2 * tmp2) % mod + (2 * tmp3) % mod) % mod;
        }

        return (colors2 + colors3) % mod;
    }
};
// 0 ms
// 7.34 MB
