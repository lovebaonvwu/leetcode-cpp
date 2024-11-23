class Solution {
public:
    int minChanges(int n, int k) {
        int ans = 0;
        for (int i = 0; i < 31; ++i) {
            if (((n & (1 << i)) > 0) && ((k & (1 << i)) == 0)) {
                ++ans;
            } else if (((n & (1 << i)) == 0) && ((k & (1 << i)) > 0)) {
                ans = -1;
                break;
            }
        }

        return ans;
    }
};
// 0 ms
// 8.00 MB
