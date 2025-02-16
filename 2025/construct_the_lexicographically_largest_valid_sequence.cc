class Solution {
    public:
        vector<int> constructDistancedSequence(int n) {
            int k = 2 * n - 1;
            vector<int> ans(k);
            vector<bool> visited(n + 1);
    
            function<bool(int)> dfs = [&](int cur) -> bool {
                if (cur == k) {
                    return true;
                }
    
                if (ans[cur] != 0) {
                    return dfs(cur + 1);
                }
    
                for (int num = n; num >= 1; --num) {
                    if (visited[num]) {
                        continue;
                    }
    
                    visited[num] = true;
                    ans[cur] = num;
    
                    if (num == 1) {
                        if (dfs(cur + 1)) {
                            return true;
                        }
                    } else if (cur + num < k && ans[cur + num] == 0) {
                        ans[cur + num] = num;
                        if (dfs(cur)) {
                            return true;
                        } 
    
                        ans[cur + num] = 0;
                    }
    
                    visited[num] = false;
                    ans[cur] = 0;
                }
    
                return false;
            };
    
            dfs(0);
    
            return ans;
        }
    };
    // 0 ms
    // 9.65 MB

