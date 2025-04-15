class FenwickTree {
    public:
        FenwickTree(int n) : tree(n + 1) { }
        void update(int index, int delta) {
            ++index;
            while (index < tree.size()) {
                tree[index] += delta;
                index += index & -index;
            }
        }
    
        int query(int index) {
            ++index;
            int res = 0;
            while (index > 0) {
                res += tree[index];
                index -= index & -index;
            }
    
            return res;
        }
    private:
        vector<int> tree;
    };
    
    class Solution {
    public:
        long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size();
    
            vector<int> pos2(n);
            vector<int> reversedIndexMapping(n);
            for (int i = 0; i < n; ++i) {
                pos2[nums2[i]] = i;
            }
    
            for (int i = 0; i < n; ++i) {
                reversedIndexMapping[pos2[nums1[i]]] = i;
            }
    
            FenwickTree tree(n);
            
            long long ans = 0;
    
            for (int value = 0; value < n; ++value) {
                int pos = reversedIndexMapping[value];
                int left = tree.query(pos);
                tree.update(pos, 1);
                int right = (n - 1 - pos) - (value - left);
                ans += (long long)left * right;
            }
    
            return ans;
        }
    };
    // Time: O(n log n)
    // Space: O(n)