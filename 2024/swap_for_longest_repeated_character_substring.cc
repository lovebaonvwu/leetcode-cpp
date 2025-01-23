class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        int ans = 0;

        for (int ch = 'a'; ch <= 'z'; ++ch) {
            int i = 0;
            int j = 0;
            int diff = 0;

            while (i < n) {
                diff += text[i++] != ch;
                if (diff > 1) {
                    diff -= text[j++] != ch;
                }
            }

            ans = max(ans, min(i - j, (int)count_if(begin(text), end(text), [ch](auto c) { return c == ch; } )));
        }

        return ans;
    }
};
// 4 ms
// 9.36 MB

