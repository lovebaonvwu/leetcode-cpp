class Solution {

    bool isSame(vector<vector<char>>& grid, int i, int j) {
        if (grid[i][j] == grid[i][j + 1] && 
            grid[i][j] == grid[i + 1][j] && 
            grid[i][j] == grid[i + 1][j + 1]) {
            return true;
        }

        return false;
    }
public:
    bool canMakeSquare(vector<vector<char>>& grid) {

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                int cntB = 0;
                int cntW = 0;

                if (grid[i][j] == 'B') {
                    ++cntB;
                } else {
                    ++cntW;
                }
                if (grid[i][j + 1] == 'B') {
                    ++cntB;
                } else {
                    ++cntW;
                }
                if (grid[i + 1][j] == 'B') {
                    ++cntB;
                } else {
                    ++cntW;
                }
                if (grid[i + 1][j + 1] == 'B') {
                    ++cntB;
                } else {
                    ++cntW;
                }

                if (abs(cntB - cntW) >= 2) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
// 0 ms
// 19.95 MB
