class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        vector<vector<vector<vector<int>>>> cached(m + 1, vector<vector<vector<int>>>(m + 1, vector<vector<int>>(n + 1, vector<int>(n + 1))));
        function<int(int, int, int, int)> dfs = [&](int top, int bottom, int left, int right) -> int {
            if (bottom - top == 1 && right - left == 1) {
                return 0;
            }

            if (cached[top][bottom][left][right] > 0) {
                return cached[top][bottom][left][right];
            }

            int ret = INT_MAX;
            for (int i = top + 1; i < bottom; ++i) {
                ret = min(ret, horizontalCut[i - 1] + dfs(top, i, left, right) + dfs(i, bottom, left, right));
            }

            for (int i = left + 1; i < right; ++i) {
                ret = min(ret, verticalCut[i - 1] + dfs(top, bottom, left, i) + dfs(top, bottom, i, right));
            }

            return cached[top][bottom][left][right] = ret;
        };

        return dfs(0, m, 0, n);
    }
};
// 416 ms
// 70.99 MB