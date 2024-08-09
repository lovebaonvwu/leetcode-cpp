class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0;
        for (int i = 0, j = 1; j < n + k - 1; ++j) {
            if (colors[j % n] == colors[(j - 1) % n]) {
                i = j;
            }

            if (j - i + 1 >= k) {
                ++ans;
            }
        }

        return ans;
    }
};
// 62 ms
// 101.48 MB