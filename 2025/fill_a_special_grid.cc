class Solution {
    void dfs(vector<vector<int>>& ans, int top, int bottom, int left, int right, int start, int end) {
        if (top == bottom && left == right) {
            ans[top][left] = start;
            return;
        }

        // Top right
        dfs(ans, 
            top, 
            top + (bottom - top) / 2, 
            left + (right - left) / 2 + 1, 
            right,
            start,
            start + (end + 1 - start) / 4 - 1);

        // Bottom right
        dfs(ans, 
            top + (bottom - top) / 2 + 1, 
            bottom, 
            left + (right - left) / 2 + 1, 
            right,
            start + (end + 1 - start) / 4,
            start + 2 * (end + 1 - start) / 4 - 1);

        // Bottom left
        dfs(ans, 
            top + (bottom - top) / 2 + 1, 
            bottom,
            left, 
            left + (right - left) / 2,
            start + 2 * (end + 1 - start) / 4,
            start + 3 * (end + 1 - start) / 4 - 1);
            
        // Top left
        dfs(ans, 
            top, 
            top + (bottom - top) / 2, 
            left, 
            left + (right - left) / 2,
            start + 3 * (end + 1 - start) / 4,
            start + 4 * (end + 1 - start) / 4 - 1);
    }
public:
    vector<vector<int>> specialGrid(int n) {
        int size = pow(2, n);
        vector<vector<int>> ans(size, vector<int>(size));

        dfs(ans, 0, size - 1, 0, size - 1, 0, pow(2, 2 * n) - 1);

        return ans;
    }
};
// Time: O(n^2)
// Space: O(n^2)
// n: number of rows and columns