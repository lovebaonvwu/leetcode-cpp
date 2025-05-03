class Solution {
    public:
        int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
            unordered_map<int, set<int>> x;
            unordered_map<int, set<int>> y;
            for (auto& b : buildings) {
                x[b[0]].insert(b[1]);
                y[b[1]].insert(b[0]);
            }
    
            int ans = 0;
    
            for (auto& b : buildings) {
                int cur_x = b[0];
                int cur_y = b[1];
    
                auto bottom = x[cur_x].lower_bound(cur_y);
                if (bottom == x[cur_x].begin()) {
                    continue;
                }
    
                auto top = x[cur_x].upper_bound(cur_y);
                if (top == x[cur_x].end()) {
                    continue;
                }
    
                auto left = y[cur_y].lower_bound(cur_x);
                if (left == y[cur_y].begin()) {
                    continue;
                }
    
                auto right = y[cur_y].upper_bound(cur_x);
                if (right == y[cur_y].end()) {
                    continue;
                }
    
                ++ans;
            }
    
            return ans;
        }
    };
    // Time: O(n * log n)
    // Space: O(n)