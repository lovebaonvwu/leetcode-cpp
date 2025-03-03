class Solution {
    public:
        int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
            int left = bounds[0][0];
            int right = bounds[0][1];
            int n = bounds.size();
            for (int i = 1; i < n; ++i) {
                int diff = original[i] - original[i - 1];
                left = max(left + diff, bounds[i][0]);
                right = min(right + diff, bounds[i][1]);
            }
    
            return max(right - left + 1, 0);
        }
    };
    // 0 ms
    // 182.17 MB
