class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n));

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], i, j});
                    visited[i][j] = true;
                }
            }
        }


        int ans = 0;
        int cur = 0;
        int dirs[] = {-1, 0, 1, 0, -1};
        while (!pq.empty()) {
            auto [h, y, x] = pq.top();
            pq.pop();

            if (cur < h) {
                cur = h;
            }

            ans += cur - h;
            for (int k = 0; k < 4; ++k) {
                int dy = y + dirs[k];
                int dx = x + dirs[k + 1];

                if (dy < 0 || dy == m || dx < 0 || dx == n) {
                    continue;
                }

                if (visited[dy][dx]) {
                    continue;
                }
                
                pq.push({heightMap[dy][dx], dy, dx});
                visited[dy][dx] = true;
            }
        }

        return ans;
    }
};
// 36 ms
// 18.76 MB
