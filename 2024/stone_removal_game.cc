class Solution {
public:
    bool canAliceWin(int n) {
        bool ans = false;
        int cnt = 10;

        while (n >= cnt) {
            n -= cnt;
            ans = !ans;
            --cnt;
        }

        return ans;
    }
};
// 0 ms
// 7.80 MB
