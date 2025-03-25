class DisjointSet {
    public:
        DisjointSet(int n) : size(n) {
            parents.resize(size);
            for (int i = 0; i < size; i += 2) {
                parents[i] = i;
                parents[i + 1] = i;
            }
    
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
    private:
        int size;
        vector<int> parents;
        vector<int> ranks;
    };
    
    class Solution {
    public:
        int minSwapsCouples(vector<int>& row) {
            int n = row.size();
            DisjointSet ds(n);
    
            for (int i = 0; i < n; i += 2) {
                ds.Union(row[i], row[i + 1]);
            }
            
            unordered_map<int, int> cnt;
            for (int i = 0; i < n; ++i) {
                ++cnt[ds.Find(i)];
            }
    
            int ans = 0;
            for (auto [_, v] : cnt) {
                ans += v / 2 - 1;
            }
    
            return ans;
        }
    };
    // Time: O(n)
    // Space: O(n)