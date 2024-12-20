class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> st;
        int n = fronts.size();
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                st.insert(fronts[i]);
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (!st.count(fronts[i])) {
                ans = min(ans, fronts[i]);
            }

            if (!st.count(backs[i])) {
                ans = min(ans, backs[i]);
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
// 4 ms
// 23.19 MB