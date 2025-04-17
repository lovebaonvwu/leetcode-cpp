class Solution {
    public:
        int uniqueXorTriplets(vector<int>& nums) {
            int n = nums.size();
    
            if (n < 3) {
                return n;
            }
            
            unordered_set<int> st;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    st.insert(nums[i] ^ nums[j]);
                }
            }
    
            unordered_set<int> cnt;
            for (auto p : st) {
                for (int i = 0; i < n; ++i) {
                    cnt.insert(p ^ nums[i]);
                }
            }
    
            return cnt.size();
        }
    };
    // Time: O(n^2)
    // Space: O(n^2)