class Solution {
    public:
        bool hasSpecialSubstring(string s, int k) {
            int n = s.size();
            for (int i = 0; i < n; ++i) {
                bool valid = true;
                for (int j = 0; j < k - 1; ++j) {
                    if (s[i + j] != s[i + j + 1]) {
                        valid = false;
                        break;
                    }
                }
    
                if (i - 1 >= 0 && s[i - 1] == s[i]) {
                    continue;
                }
    
                if (i + k < n && s[i + k - 1] == s[i + k]) {
                    continue;
                }
    
                if (valid) {
                    return true;
                }
            }
    
            return false;
        }
    };
    // 2 ms
    // 8.47 MB
