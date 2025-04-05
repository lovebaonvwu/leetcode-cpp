class Solution {
    public:
        vector<int> minCosts(vector<int>& cost) {
            int n = cost.size();
    
            vector<int> prevSmaller(n);
            for (int i = 0, prev = INT_MAX; i < n; ++i) {
                prevSmaller[i] = min(prev, cost[i]);
                prev = min(prev, cost[i]);
            }
    
            vector<int> ans(n);
            for (int i = 0; i < n; ++i) {
                ans[i] = prevSmaller[i];
            }
    
            return ans;
        }
    };
    // Time: O(n)
    // Space: O(n)