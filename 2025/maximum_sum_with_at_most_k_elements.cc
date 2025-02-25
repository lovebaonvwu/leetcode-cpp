class Solution {
    public:
        long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
            int n = grid.size();
            int m = grid[0].size();
    
            for (auto& row : grid) {
                sort(rbegin(row), rend(row));
            }
    
            priority_queue<int> pq;
    
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m && j < limits[i]; ++j) {
                    pq.push(grid[i][j]);
                }
            }
    
            long long ans = 0;
            while (!pq.empty() && k-- > 0) {
                ans += pq.top();
                pq.pop();
            }
    
            return ans;
        }
    };
    // 188 ms
    // 110.11 MB