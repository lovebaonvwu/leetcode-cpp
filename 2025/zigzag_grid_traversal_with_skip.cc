class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> ans;

        int cnt = (m * n + 1) / 2;

        for (int i = 0; i < m; i += 2) {
            for (int j = 0; j < n; j += 2) {
                ans.push_back(grid[i][j]);
            }

            if (i + 1 < m) {
                int j = n - 1;
                if (n % 2 != 0) {
                    j = n - 2;
                }
                for (; j >= 0; j -= 2) {
                    ans.push_back(grid[i + 1][j]);
                }
            }
        }

        return ans;
    }
};
// 1 ms
// 31.77 MB

