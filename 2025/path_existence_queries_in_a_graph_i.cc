class DisjointSet {
    public:
        DisjointSet(int n) : size(n) {
            parents.resize(size);
            iota(begin(parents), end(parents), 0);
    
            ranks.resize(n);
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
    
            if (ranks[px] > ranks[py]) {
                parents[py] = px;
                ++ranks[px];
            } else {
                parents[px] = py;
                ++ranks[py];
            }
        }
    private:
        vector<int> parents;
        vector<int> ranks;
        int size;
    };
    
    class Solution {
    public:
        vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
            DisjointSet dst(n);
    
            for (int i = 0; i < n - 1; ++i) {
                if (abs(nums[i] - nums[i + 1]) <= maxDiff) {
                    dst.Union(i, i + 1);
                }
            }
    
            vector<bool> ans;
            for (auto& q : queries) {
                int px = dst.Find(q[0]);
                int py = dst.Find(q[1]);
    
                ans.push_back(px == py);
            }
    
            return ans;
        }
    };
    // Time: O(n + m)
    // Space: O(n)
    // n = number of elements in nums
    // m = number of queries
    // The time complexity of the Union-Find algorithm is O(α(n)), where α is the inverse Ackermann function.
    // The space complexity is O(n) for the parent and rank arrays.