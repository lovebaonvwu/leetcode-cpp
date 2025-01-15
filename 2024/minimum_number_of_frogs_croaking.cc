class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int cnt[5] = {0, 0, 0, 0, 0};

        for (auto c : croakOfFrogs) {
            if (c == 'c') {
                ++cnt[0];
                if (cnt[4] > 0) {
                    --cnt[4];
                }
            } else if (c == 'r') {
                ++cnt[1];
                if (cnt[0] == 0) {
                    return -1;
                }
                --cnt[0];
            } else if (c == 'o') {
                ++cnt[2];
                if (cnt[1] == 0) {
                    return -1;
                }
                --cnt[1];
            } else if (c == 'a') {
                ++cnt[3];
                if (cnt[2] == 0) {
                    return -1;
                }
                --cnt[2];
            } else if (c == 'k') {
                ++cnt[4];
                if (cnt[3] == 0) {
                    return -1;
                }
                --cnt[3];
            }
        }

        if (any_of(begin(cnt), end(cnt) - 1, [](auto c) { return c > 0; })) {
            return -1;
        }

        return cnt[4];
    }
};
// 5 ms
// 11.8 MB