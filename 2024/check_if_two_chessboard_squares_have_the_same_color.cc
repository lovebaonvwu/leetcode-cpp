class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int y1 = coordinate1[0] - 'a';
        int y2 = coordinate2[0] - 'a';
        int x1 = coordinate1[1] - '0';
        int x2 = coordinate2[1] - '0';
        if (y1 % 2 == y2 % 2) {
            return x1 % 2 == x2 % 2;
        } else {
            return x1 % 2 != x2 % 2;
        }
    }
};
// 4 ms
// 8.00 MB
