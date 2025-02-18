class Solution {
    double helper(const vector<vector<int>>& squares, double md) {
        double upper = 0;
        double lower = 0;

        for (auto& square : squares) {
            int x = square[0];
            int y = square[1];
            int len = square[2];

            if (y >= md) {
                upper += 1.0 * len * len;
            } else if (y + len <= md) {
                lower += 1.0 * len * len;
            } else {
                lower += 1.0 * len * (md - y);
                upper += 1.0 * len * (y + len - md);
            }
        }

        return upper - lower;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        double lo = 0;
        double hi = 2 * 1e9;

        int round = 60;
        while (round-- > 0) {
            double md = (lo + hi) / 2;
            if (helper(squares, md) > 0) {
                lo = md;
            } else {
                hi = md;
            }
        }

        return lo;
    }
};
// 116 ms
// 182.20 MB
