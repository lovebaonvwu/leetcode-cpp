class Solution {
public:
    string stringHash(string s, int k) {
        string ans;
        for (int i = 0; i < s.size(); i += k) {
            int val = 0;
            for (int j = 0; j < k; ++j) {
                val += s[i + j] - 'a';
            }

            ans += val % 26 + 'a';
        }

        return ans;
    }
};
// 7 ms
// 10.38 MB