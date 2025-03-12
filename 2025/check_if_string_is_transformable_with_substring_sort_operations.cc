class Solution {
    public:
        bool isTransformable(string s, string t) {
            int n = s.size();
            vector<queue<int>> pos(10);
    
            for (int i = 0; i < n; ++i) {
                pos[s[i] - '0'].push(i);
            }
    
            for (auto ch : t) {
                int d = ch - '0';
                if (pos[d].empty()) {
                    return false;
                }
                
                int limit = pos[d].front();
    
                for (int i = 0; i < d; ++i) {
                    if (pos[i].empty()) {
                        continue;
                    }
    
                    if (pos[i].front() < limit) {
                        return false;
                    }
                }
    
                pos[d].pop();
            }
    
            return true;
        }
    };
    // 18 ms
    // 21.71 MB
