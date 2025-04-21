class Solution {
    public:
        int maximumPossibleSize(vector<int>& nums) {
            int ans = 0;
            int prev = -1;
            for (auto n : nums) {
                if (n >= prev) {
                    ++ans;
                    prev = n;
                }
            }
    
            return ans;
        }
    };
    // Time: O(n)
    // Space: O(1)