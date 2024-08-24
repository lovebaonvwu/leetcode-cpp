class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0;
        int j = 0;
        for (auto& c : commands) {
            if (c == "UP") {
                --i;
            } else if (c == "RIGHT") {
                ++j;
            } else if (c == "DOWN") {
                ++i;
            } else if (c == "LEFT") {
                --j;
            }
        }

        return i * n + j;
    }
};
// 12 ms
// 35.04 MB
