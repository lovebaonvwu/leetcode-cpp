class Solution {
    int m;
    int n;
    bool check(vector<vector<int>> mat, int mask) {
        int dirs[] = {-1, 0, 1, 0, -1};

        for (int i = 0; i < m * n; ++i) {
            if (mask & (1 << i)) {
                int y = i / n;
                int x = i % n;

                mat[y][x] = (mat[y][x] + 1) % 2;
                for (int k = 0; k < 4; ++k) {
                    int dy = y + dirs[k];
                    int dx = x + dirs[k + 1];

                    if (dy < 0 || dy == m || dx < 0 || dx == n) {
                        continue;
                    }

                    mat[dy][dx] = (mat[dy][dx] + 1) % 2;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }
public:
    int minFlips(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();

        int ans = INT_MAX;

        for (int mask = 0; mask < (1 << (m * n)); ++mask) {
            if (check(mat, mask)) {
                ans = min(ans, static_cast<int>(bitset<9>(mask).count()));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
// 5 ms
// 8.72 MB