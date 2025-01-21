class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long total = accumulate(begin(grid[0]), end(grid[0]), 0LL);
        long long ans = LONG_LONG_MAX;
        long long sum = 0;
        for (int i = 0; i < grid[0].size(); ++i) {
            total -= grid[0][i];
            ans = min(ans, max(total, sum));
            sum += grid[1][i];
        }

        return ans;
    }
};
// 0 ms
// 66.82 MB
