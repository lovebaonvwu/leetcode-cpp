class Solution {
    public:
        int uniqueXorTriplets(vector<int>& nums) {
            int n = nums.size();
    
            if (n < 3) {
                return n;
            }
    
            int i = 30;
            for (; i >= 0; --i) {
                if ((n >> i) & 1) {
                    break;
                }
            }
    
            return pow(2, i + 1);
        }
    };
    // Time: O(log n)
    // Space: O(1)