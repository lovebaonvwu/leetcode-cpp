class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> banned(begin(bannedWords), end(bannedWords));
        int cnt = 0;
        for (auto& m : message) {
            if (banned.find(m) != banned.end()) {
                ++cnt;
            }

            if (cnt >= 2) {
                break;
            }
        }

        return cnt >= 2;
    }
};
// 470 ms
// 288.66 MB
