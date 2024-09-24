class Solution {
    bool check(const vector<int>& cnt, const vector<int>& pattern) {
        bool ret = true;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] < pattern[i]) {
                ret = false;
                break;
            }
        }

        return ret;
    }
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> pattern(26);
        for (auto c : word2) {
            ++pattern[c - 'a'];
        }

        int n = word1.size();
        vector<int> cnt(26);
        long long ans = 0;
        for (int i = 0, j = 0; j < n;) {
            ++cnt[word1[j] - 'a'];
            if (check(cnt, pattern)) {
                --cnt[word1[i] - 'a'];
                --cnt[word1[j] - 'a'];
                ++i;
                ans += (n - j);
            } else {
                ++j;
            }
        }

        return ans;
    }
};
// 861 ms
// 46.64 MB