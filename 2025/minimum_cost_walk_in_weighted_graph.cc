class DisjointSet {
    public:
        DisjointSet(int n) : size(n) {
            parents.resize(n);
            ranks.assign(n, 0);
            costs.assign(n, INT_MAX);
            iota(begin(parents), end(parents), 0);
        }
    
        int Find(int x) {
            if (parents[x] != x) {
                parents[x] = Find(parents[x]);
                costs[x] = costs[parents[x]];
            }
    
            return parents[x];
        }
    
        void Union(int x, int y, int w) {
            int px = Find(x);
            int py = Find(y);
    
            if (ranks[px] >= py) {
                parents[py] = px;
                ++ranks[px];
                costs[px] = costs[px] & w & costs[py];
            } else {
                parents[px] = py;
                ++ranks[py];
                costs[py] = costs[px] & w & costs[py];
            }
        }
    
        int getCost(int x) {
            return costs[x];
        }
    
    private:
        vector<int> parents;
        vector<int> ranks;
        vector<int> costs;
        int size;
    };
    
    class Solution {
    public:
        vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
            unordered_map<int, vector<pair<int ,int>>> g;
    
            DisjointSet ds(n);
    
            for (auto e : edges) {
                g[e[0]].push_back({e[1], e[2]});
                g[e[1]].push_back({e[0], e[2]});
    
                ds.Union(e[0], e[1], e[2]);
            }
    
            vector<int> ans;
    
            for (auto q : query) {
                int px = ds.Find(q[0]);
                int py = ds.Find(q[1]);
    
                if (px != py) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(ds.getCost(px));
                }
            }
    
            return ans;
        }
    };
// Time: O(m + q)
// Space: O(n)