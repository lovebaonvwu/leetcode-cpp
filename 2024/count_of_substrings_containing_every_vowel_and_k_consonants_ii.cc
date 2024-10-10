class Solution {
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    long long countOfSubstrings(string word, int k) {
        int a = 0;
        int e = 0;
        int i = 0;
        int o = 0;
        int u = 0;
        int v = 0;
        int n = word.size();

        vector<int> cnt(n);
        if (isVowel(word[n - 1])) {
            cnt[n - 1] = 1;
        }

        for (int j = n - 2; j >= 0; --j) {
            if (isVowel(word[j])) {
                cnt[j] = cnt[j + 1] + 1;
            }
        }

        long long ans = 0;
        for (int p = 0, q = 0; p < n; ++p) {
            while (q < n && (!(a > 0 && e > 0 && i > 0 && o > 0 && u > 0) || v < k)) {
                if (word[q] == 'a') 
                    ++a;
                else if (word[q] == 'e') 
                    ++e;
                else if (word[q] == 'i') 
                    ++i;
                else if (word[q] == 'o') 
                    ++o;
                else if (word[q] == 'u') 
                    ++u;
                else
                    ++v;

                ++q;
            }

            if ((a > 0 && e > 0 && i > 0 && o > 0 && u > 0) && v == k) {
                ans += 1 + (q < n ? cnt[q] : 0);
            }

            if (word[p] == 'a') 
                --a;
            else if (word[p] == 'e') 
                --e;
            else if (word[p] == 'i') 
                --i;
            else if (word[p] == 'o') 
                --o;
            else if (word[p] == 'u') 
                --u;
            else
                --v;
        }

        return ans;
    }
};
// 173 ms
// 49.29 MB
