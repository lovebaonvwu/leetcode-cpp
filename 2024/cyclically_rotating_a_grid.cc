class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int top = 0;
        int bottom = grid.size() - 1;
        int left = 0;
        int right = grid[0].size() - 1;

        while (top < bottom && left < right) {
            int counts = 2 * (bottom - top + 1) + 2 * (right - left + 1) - 4;
            int moves = k % counts;

            while (moves-- > 0) {
                int head = grid[top][left];
                for (int j = left; j < right; ++j) {
                    grid[top][j] = grid[top][j + 1];
                }

                for (int i = top; i < bottom; ++i) {
                    grid[i][right] = grid[i + 1][right];
                }

                for (int j = right; j > left; --j) {
                    grid[bottom][j] = grid[bottom][j - 1];
                }

                for (int i = bottom; i > top; --i) {
                    grid[i][left] = grid[i - 1][left];
                }

                grid[top + 1][left] = head;
            }
            ++top, --bottom, ++left, --right;
        }

        return grid;
    }
};
// 12 ms
// 16.74 MB

