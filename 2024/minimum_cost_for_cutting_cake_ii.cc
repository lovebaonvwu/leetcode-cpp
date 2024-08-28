class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(rbegin(horizontalCut), rend(horizontalCut));
        sort(rbegin(verticalCut), rend(verticalCut));

        int i = 0;
        int j = 0;
        long long ans = 0;
        while (i < m - 1 && j < n - 1) {
            if (horizontalCut[i] >= verticalCut[j]) {
                ans += horizontalCut[i] * (j + 1);
                ++i;
            } else {
                ans += verticalCut[j] * (i + 1);
                ++j;
            }
        }

        while (i < m - 1) {
            ans += horizontalCut[i++] * n;

        }

        while (j < n - 1) {
            ans += verticalCut[j++] * m;
        }

        return ans;
    }
};
// 505 ms
// 234.79 MB