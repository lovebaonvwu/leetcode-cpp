class Solution {
public:
    string findValidPair(string s) {
        unordered_map<char, int> cnt;
        for (auto c : s) {
            ++cnt[c];
        }

        for (int i = 0; i < s.size() - 1; ++i) {
            if (cnt[s[i]] == s[i] - '0' && cnt[s[i + 1]] == s[i + 1] - '0' && s[i] != s[i + 1]) {
                return s.substr(i, 2);
            }
        }

        return "";
    }
};
// 3 ms
// 9.12 MB
