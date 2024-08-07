class Solution {
public:
    int maxOperations(string s) {
        int ans = 0;
        for (int i = s.size() - 1, cnt = 0; i > 0; --i) {
            if (s[i] == '0' && s[i - 1] == '1') {
                ++cnt;
                ans += cnt;
            } else if (s[i] == '1' && s[i - 1] == '1') {
                ans += cnt;
            }
        }

        return ans;
    }
};
// 27 ms
// 14.21 MB
