class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            vector<int> cnt(101);
    
            for (auto n : nums) {
                ++cnt[n];
            }
    
            int ans = 0;
            for (int i = 0; i < 101; ++i) {
                if (cnt[i] > 0) {
                    if (i < k) {
                        return -1;
                    }
    
                    ans += i > k;
                }
            }
    
            return ans;
        }
    };
    // Time: O(n)
    // Space: O(n)