class Solution {
    public:
        vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
            int n = conversions.size();
    
            unordered_map<int, vector<pair<int, int>>> g;
            for (auto& c : conversions) {
                g[c[0]].push_back({c[1], c[2]});
                g[c[1]].push_back({c[0], c[2]});
            }
    
            int mod = 1e9 + 7;
            vector<int> ans(n + 1);
    
            function<void(int, int, long long)> dfs = [&](int root, int parent, long long factor) -> void {
                ans[root] = factor;
                for (auto& [neighbor, v] : g[root]) {
                    if (neighbor != parent) {
                        dfs(neighbor, root, factor * v % mod);
                    }
                }
            };
    
            dfs(0, -1, 1);
    
            return ans;
        }
    };
    // Time: O(n)
    // Space: O(n)

    class Solution {
        vector<int> ans;
        int mod = 1e9 + 7;
    
        void dfs(unordered_map<int, vector<pair<int, int>>>& g, int root, int parent, long long factor) {
                ans[root] = factor;
                for (auto& [neighbor, v] : g[root]) {
                    if (neighbor != parent) {
                        dfs(g, neighbor, root, factor * v % mod);
                    }
                }
            }
    public:
        vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
            int n = conversions.size();
    
            unordered_map<int, vector<pair<int, int>>> g;
            for (auto& c : conversions) {
                g[c[0]].push_back({c[1], c[2]});
                g[c[1]].push_back({c[0], c[2]});
            }
    
            ans.resize(n + 1);
    
            dfs(g, 0, -1, 1);
    
            return ans;
        }
    };
    // Time: O(n)
    // Space: O(n)