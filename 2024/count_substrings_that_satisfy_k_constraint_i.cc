class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int cnt0 = 0;
            int cnt1 = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] == '0') {
                    ++cnt0;
                } else {
                    ++cnt1;
                }

                if (cnt0 <= k || cnt1 <= k) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};
// 3 ms
// 8.71 MB
