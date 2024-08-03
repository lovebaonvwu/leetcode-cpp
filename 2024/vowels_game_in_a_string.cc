class Solution {
public:
    bool doesAliceWin(string s) {
        int cnt = 0;
        for (auto c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ++cnt;
            }
        }

        return cnt > 0;
    }
};
// 44 ms
// 17.32 MB

class Solution {
public:
    bool doesAliceWin(string s) {
        for (auto c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                return true;
            }
        }

        return false;
    }
};
// 31 ms
// 17.32 MB
