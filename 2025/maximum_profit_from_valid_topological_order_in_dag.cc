class Solution {
    public:
        int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
            vector<vector<int>> g(n);
            vector<int> indegree(n);
    
            for (auto& e : edges) {
                g[e[0]].push_back(e[1]);
                ++indegree[e[1]];
            }
    
            vector<bool> visited(n);
    
            function<int(int)> dfs = [&](int pos) -> int {
                int ret = 0;
                for (int i = 0; i < n; ++i) {
                    if (indegree[i] == 0 && !visited[i]) {
                        visited[i] = true;
                        for (auto next : g[i]) {
                            --indegree[next];
                        }
                        ret = max(ret, score[i] * pos + dfs(pos + 1));
                        for (auto next : g[i]) {
                            ++indegree[next];
                        }
                        visited[i] = false;
                    }
                }
                
                return ret;
            };
    
            return dfs(1);
        }
    };
    // Time: O(n!)
    // Space: O(n)

class Solution {

        int dfs(int pos, int state, int n, vector<int>& cached, vector<int>& indegree, vector<vector<int>>& g, vector<int>& score) {

            if (pos > n) {
                return 0;
            }
            
            if (cached[state] != -1) {
                return cached[state];
            }

            int ret = 0;
            for (int i = 0; i < n; ++i) {
                if (indegree[i] == 0 && !(state & (1 << i))) {
                    state |= (1 << i);
                    for (auto next : g[i]) {
                        --indegree[next];
                    }
                    ret = max(ret, score[i] * pos + dfs(pos + 1, state, n, cached, indegree, g, score));
                    for (auto next : g[i]) {
                        ++indegree[next];
                    }
                    state ^= (1 << i);
                }
            }

            return cached[state] = ret;
        };
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        vector<vector<int>> g(n);
        vector<int> indegree(n);

        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            ++indegree[e[1]];
        }

        vector<int> cached((1 << 22) - 1, -1);

        return dfs(1, 0, n, cached, indegree, g, score);
    }
};
// Time: O(n!)
// Space: O(n)

class Solution {

    int dfs(int pos, int state, int n, vector<int>& cached, vector<int>& indegree, vector<vector<int>>& g, vector<int>& score) {

        if (pos > n) {
            return 0;
        }
        
        if (cached[state] != -1) {
            return cached[state];
        }

        int ret = 0;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0 && !(state & (1 << i))) {
                state |= (1 << i);
                for (auto next : g[i]) {
                    --indegree[next];
                }
                ret = max(ret, score[i] * pos + dfs(pos + 1, state, n, cached, indegree, g, score));
                for (auto next : g[i]) {
                    ++indegree[next];
                }
                state ^= (1 << i);
            }
        }

        return cached[state] = ret;
    };
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        vector<vector<int>> g(n);
        vector<int> indegree(n);

        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            ++indegree[e[1]];
        }

        vector<int> cached((1 << n) - 1, -1);

        return dfs(1, 0, n, cached, indegree, g, score);
    }
};
// Time: O(n!)
// Space: O(n)