class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minValue = arrays[0][0];
        int maxValue = arrays[0].back();

        int ans = 0;
        for (int i = 1; i < arrays.size(); ++i) {
            ans = max(ans, max(maxValue - arrays[i][0], arrays[i].back() - minValue));
            minValue = min(minValue, arrays[i][0]);
            maxValue = max(maxValue, arrays[i].back());
        }

        return ans;
    }
};
// 223 ms
// 107.91 MB