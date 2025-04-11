class Solution {
    public:
        int minStickers(vector<string>& stickers, string target) {
            int n = target.size();
            int m = (1 << n);
            vector<int> dp(m, INT_MAX);
            dp[0] = 0;
    
            for (int i = 0; i < m; ++i) {
                if (dp[i] == INT_MAX) {
                    continue;
                }
    
                for (auto& s : stickers) {
                    int next = nextState(target, s, i);
                    dp[next] = min(dp[next], dp[i] + 1);
                }
            }
    
            return dp[m - 1] == INT_MAX ? - 1 : dp[m - 1];
        }
    
        int nextState(const string& target, const string& s, int state) {
            int n = target.size();
    
            for (auto ch : s) {
                for (int i = 0; i < n; ++i) {
                    if (((state >> i) & 1) == 0 && ch == target[i]) {
                        state |= (1 << i);
                        break;
                    }
                }
            }
    
            return state;
        }
    };
    // Time: O(n * m * 2^n)
    // Space: O(2^n)
    // n: target.size()
    // m: stickers.size()