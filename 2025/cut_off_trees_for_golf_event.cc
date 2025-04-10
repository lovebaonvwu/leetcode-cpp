class Solution {
    public:
        int cutOffTree(vector<vector<int>>& forest) {
            priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
    
            int m = forest.size();
            int n = forest[0].size();
    
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (forest[i][j] > 1) {
                        pq.push({forest[i][j], i, j});
                    }
                }
            }
    
            int ans = 0;
    
            int src_y = 0;
            int src_x = 0;
    
            int dirs[] = {-1, 0, 1, 0, -1};
    
            while (!pq.empty()) {
                auto [h, dst_y, dst_x] = pq.top();
                pq.pop();
    
                queue<pair<int, int>> q;
                q.push({src_y, src_x});
    
                vector<vector<bool>> visited(m, vector<bool>(n));
                visited[src_y][src_x] = true;
    
                int step = 0;
                bool find = false;
    
                while (!q.empty()) {
                    int cnt = q.size();
    
                    while (cnt -- > 0) {
                        auto [cur_y, cur_x] = q.front();
                        q.pop();
    
                        if (cur_y == dst_y && cur_x == dst_x) {
                            src_y = dst_y;
                            src_x = dst_x;
    
                            find = true;
                            break;
                        }
    
                        for (int k = 0; k < 4; ++k) {
                            int dy = cur_y + dirs[k];
                            int dx = cur_x + dirs[k + 1];
    
                            if (dy < 0 || dy == m || dx < 0 || dx == n) {
                                continue;
                            }
    
                            if (visited[dy][dx] || forest[dy][dx] == 0) {
                                continue;
                            }
    
                            visited[dy][dx] = true;
                            q.push({dy, dx});
                        }
                    }
    
                    if (find) {
                        break;
                    }
    
                    ++step;
                }
    
    
                if (src_y != dst_y || src_x != dst_x) {
                    return -1;
                }
    
                ans += step;
            }
    
            return ans;
        }
    };
    // Time: O((m * n)^2)
    // Space: O(m * n)