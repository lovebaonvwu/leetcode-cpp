class Solution {
    bool valid(const vector<int>& cnt, const vector<int>& pattern) {
        bool ret = true;
        for (int i = 0; i < pattern.size(); ++i) {
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

        vector<int> cnt(26);
        int m = word2.size();
        int n = word1.size();
        long long ans = 0;
        for (int i = 0, j = 0; j < n;) {
            ++cnt[word1[j] - 'a'];

            if (valid(cnt, pattern)) {
                ans += n - j;
                --cnt[word1[i] - 'a'];
                --cnt[word1[j] - 'a'];
                ++i;
            } else {
                ++j;
            }
        }

        return ans;
    }
};
// 67 ms
// 13.59 MB
