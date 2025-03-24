class DisjointSet {
    public:
        DisjointSet(int n) : size(n) {
            parents.resize(size);
            iota(begin(parents), end(parents), 0);
            ranks.assign(size, 0);
        }
    
        int Find(int x) {
            if (parents[x] != x) {
                parents[x] = Find(parents[x]);
            }
    
            return parents[x];
        }
    
        void Union(int x, int y) {
            int px = Find(x);
            int py = Find(y);
    
            if (px == py) {
                return;
            }
    
            if (ranks[px] >= ranks[py]) {
                parents[py] = px;
                ++ranks[px];
            } else {
                parents[px] = py;
                ++ranks[py];
            }
        }
    
        int Components() {
            int count = 0;
            for (int i = 0; i < size; ++i) {
                Find(i);
                if (parents[i] == i) {
                    ++count;
                }
            }
    
            return count;
        }
    private:
        vector<int> parents;
        vector<int> ranks;
        int size;
    };
    
    class Solution {
    public:
        int numberOfComponents(vector<vector<int>>& properties, int k) {
            vector<unordered_set<int>> props;
            for (auto p : properties) {
                props.push_back(unordered_set(begin(p), end(p)));
            }
    
            int n = properties.size();
            DisjointSet ds(n);
    
            for (int i = 0; i < n; ++i) {
                auto si = props[i];
                for (int j = i + 1; j < n; ++j) {
                    auto sj = props[j];
    
                    int cnt = 0;
                    for (auto x : si) {
                        if (sj.find(x) != sj.end()) {
                            ++cnt;
                        }
                    }
    
                    if (cnt >= k) {
                        ds.Union(i, j);
                    }
                }
            }
    
            return ds.Components();
        }
    };
    // Time: O(n^3)
    // Space: O(n)