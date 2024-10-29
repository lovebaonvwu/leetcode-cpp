class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> cnt(26);
        for (auto c : s) {
            ++cnt[c - 'a'];
        }

        int mod = 1e9 + 7;
        while (t-- > 0) {
            vector<int> tmp(26);
            for (int i = 0; i < cnt.size(); ++i) {
                if (i < 25) {
                    tmp[i + 1] = cnt[i];
                } else {
                    tmp[0] = (tmp[0] + cnt[i]) % mod;
                    tmp[1] = (tmp[1] + cnt[i]) % mod;
                }
            }

            cnt = tmp;
        }

        int ans = 0;
        for (auto c : cnt) {
            ans = (ans + c) % mod;
        }

        return ans;
    }
};
// 961 ms
// 493.66 MB

