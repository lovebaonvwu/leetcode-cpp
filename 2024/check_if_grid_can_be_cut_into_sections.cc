class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        sort(begin(rectangles), end(rectangles), [](auto& a, auto& b) {
            return a[0] < b[0];
        });

        int cnt = 0;
        int prevend = rectangles[0][2];
        for (int i = 1; i < rectangles.size(); ++i) {
            if (rectangles[i][0] >= prevend) {
                ++cnt;
                prevend = rectangles[i][2];
            } else {
                prevend = max(prevend, rectangles[i][2]);
            }
        }

        if (cnt >= 2) {
            return true;
        }

        sort(begin(rectangles), end(rectangles), [](auto& a, auto& b) {
            return a[1] < b[1];
        });

        cnt = 0;
        prevend = rectangles[0][3];
        for (int i = 1; i < rectangles.size(); ++i) {
            if (rectangles[i][1] >= prevend) {
                ++cnt;
                prevend = rectangles[i][3];
            } else {
                prevend = max(prevend, rectangles[i][3]);
            }
        }

        if (cnt >= 2) {
            return true;
        }

        return false;
    }
};
// 96 ms
// 185.54 MB
