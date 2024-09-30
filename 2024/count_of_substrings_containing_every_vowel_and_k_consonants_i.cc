class Solution {
public:
    int countOfSubstrings(string word, int k) {
        int ans = 0;
        int n = word.size();
        for (int p = 0; p < n; ++p) {
            int a = 0;
            int e = 0;
            int i = 0;
            int o = 0;
            int u = 0;
            int cnt = 0;
            for (int q = p; q < n; ++q) {
                if (word[q] == 'a') {
                    ++a;
                } else if (word[q] == 'e') {
                    ++e;
                } else if (word[q] == 'i') {
                    ++i;
                } else if (word[q] == 'o') {
                    ++o;
                } else if (word[q] == 'u') {
                    ++u;
                } else {
                    ++cnt;
                }

                if (a > 0 && e > 0 && i > 0 && o > 0 && u > 0 && cnt == k) {
                    ++ans;
                }
            }
        }

        return ans;
    }
};
// 16 ms
// 8.83 MB
