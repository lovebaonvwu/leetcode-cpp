class Solution {
    int test(int red, int blue) {
        int ret = 0;
        bool curRed = true;
        int cnt = 1;

        while (true) {
            if (curRed && red < cnt) {
                break;
            }

            if (!curRed && blue < cnt) {
                break;
            }

            if (curRed) {
                red -= cnt;
            } else {
                blue -= cnt;
            }

            ++cnt;
            ++ret;
            curRed = !curRed;
        }

        return ret;
    }
public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(test(red, blue), test(blue, red));
    }
};
// 0 ms
// 8.28 MB

