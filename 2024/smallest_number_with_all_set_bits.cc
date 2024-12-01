class Solution {
public:
    int smallestNumber(int n) {
        int i = 30;
        for (; i >= 0; --i) {
            if (n & (1 << i)) {
                break;
            }
        }

        int ans = 1;
        while (i-- > 0) {
            ans = (ans << 1) | 1;
        }

        return ans;
    }
};
// 0 ms
// 8.30 MB
