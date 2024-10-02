class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(rbegin(maximumHeight), rend(maximumHeight));
        long long ans = maximumHeight[0];
        int next = maximumHeight[0] - 1;
        int n = maximumHeight.size();

        for (int i = 1; i < n; ++i) {
            if (next == 0) {
                return -1;
            }

            ans += min(next, maximumHeight[i]);
            next = min(next - 1, maximumHeight[i] - 1);
        }

        return ans;
    }
};
// 293 ms
// 121.24 MB

