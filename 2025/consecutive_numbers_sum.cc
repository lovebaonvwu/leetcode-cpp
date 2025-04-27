class Solution {
    public:
        int consecutiveNumbersSum(int n) {
            int ans = 0;
    
            for (int m = 1; m * m <= 2 * n; ++m) {
                if ((2 * n - m * m + m) % (2 * m) == 0 && 2 * n - m * m + m > 0) {
                    ++ans;
                }
            }
    
            return ans;
        }
    };
    // Time: O(sqrt(n))
    // Space: O(1)