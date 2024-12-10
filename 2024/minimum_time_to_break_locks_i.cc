class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) {
        int n = strength.size();
        function<int(int, int)> dfs = [&](int x, int mask) -> int {
            if (mask == (1 << n) - 1) {
                return 0;
            }

            int ret = INT_MAX;
            for (int i = 0; i < n; ++i) {
                if (!((1 << i) & mask)) {
                    int e = (strength[i] + x - 1) / x;
                    ret = min(ret, e + dfs(x + K, mask | (1 << i)));
                }
            }

            return ret;
        };

        return dfs(1, 0);
    }
};
// 650 ms
// 26.36 MB
