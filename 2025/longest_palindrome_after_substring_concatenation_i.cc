class Solution {
    bool isPalindrome(const string& s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
public:
    int longestPalindrome(string s, string t) {
        unordered_set<string> s1;
        int m = s.size();
        for (int i = 0; i < m; ++i) {
            for (int j = i; j < m; ++j) {
                s1.insert(s.substr(i, j - i + 1));
            }
        }

        unordered_set<string> s2;
        int n = t.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                s2.insert(t.substr(i, j - i + 1));
            }
        }

        size_t ans = 0;
        for (auto& a : s1) {
            for (auto& b : s2) {
                if (isPalindrome(a + b)) {
                    ans = max(ans, a.size() + b.size());
                }
                if (isPalindrome(a)) {
                    ans = max(ans, a.size());
                }
                if (isPalindrome(b)) {
                    ans = max(ans, b.size());
                }
            }
        }


        return ans;
    }
};
// Time: O(n^5)
// Space: O(n)