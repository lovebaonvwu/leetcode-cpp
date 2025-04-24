class Solution {
    public:
        int uniqueLetterString(string s) {
            int n = s.size();
            vector<vector<int>> cnt(26);
            for (int i = 0; i < 26; ++i) {
                cnt[i].push_back(-1);
            }
    
            for (int i = 0; i < n; ++i) {
                cnt[s[i] - 'A'].push_back(i);
            }
    
            for (int i = 0; i < 26; ++i) {
                cnt[i].push_back(n);
            }
    
            int ans = 0;
    
            for (auto& c : cnt) {
                for (int i = 1; i < c.size() - 1; ++i) {
                    ans += (c[i] - c[i - 1]) * (c[i + 1] - c[i]);
                }
            }
    
            return ans;
        }
    };
    // Time: O(n)
    // Space: O(n)