class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";

        while (s.size() < k) {
            string t;

            for (auto c : s) {
                t += ((c - 'a' + 1) % 26) + 'a';
            }

            s += t;
        }

        return s[k - 1];
    }
};
// 4 ms
// 10.12 MB
