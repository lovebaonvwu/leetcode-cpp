class Solution {
public:
    string losingPlayer(int x, int y) {
        bool aliceWin = false;

        while (x >= 1 && y >= 4) {
            --x;
            y -= 4;
            aliceWin = !aliceWin;
        }

        return aliceWin ? "Alice" : "Bob";
    }
};
// 2 ms
// 7.66 MB

