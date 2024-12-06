class Solution {
    bool isAnagrams(const string& s, int k) {
        vector<int> cnt(26);
        for (int i = 0; i < k; ++i) {
            ++cnt[s[i] - 'a'];
        }

        for (int i = k; i < s.size(); i += k) {
            vector<int> tmp(26);
            for (int j = i; j < i + k; ++j) {
                ++tmp[s[j] - 'a'];
            }

            if (cnt != tmp) {
                return false;
            }
        }

        return true;
    }
public:
    int minAnagramLength(string s) {
        int n = s.size();

        for (int i = 1; i <= n; ++i) {
            if (n % i == 0 && isAnagrams(s, i)) {
                return i;
            }
        }

        return n;
    }
};
// 147 ms
// 120.28 MB
