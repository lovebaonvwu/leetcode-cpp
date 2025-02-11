class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pair<int, int>> qs;

        int k = queries.size();
        for (int i = 0; i < k; ++i) {
            qs.push_back({queries[i], i});
        }

        sort(begin(qs), end(qs));

        vector<int> ans(k);

        int m = grid.size();
        int n = grid[0].size();

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        vector<vector<bool>> visited(m, vector<bool>(n));
        visited[0][0] = true;
        int cnt = 0;

        int dirs[] = {-1, 0, 1, 0, -1};
        for (auto& [bar, idx] : qs) {
            while (!pq.empty()) {
                auto [val, y, x] = pq.top();

                if (bar <= val) {
                    break;
                }

                pq.pop();
                ++cnt;

                for (int k = 0; k < 4; ++k) {
                    int dy = y + dirs[k];
                    int dx = x + dirs[k + 1];

                    if (dy < 0 || dy == m || dx < 0 || dx == n) {
                        continue;
                    }

                    if (visited[dy][dx]) {
                        continue;
                    }

                    pq.push({grid[dy][dx], dy, dx});
                    visited[dy][dx] = true;
                }
            }

            ans[idx] = cnt;
        }

        return ans;
    }
};
// 127 ms
// 41.17 MB

