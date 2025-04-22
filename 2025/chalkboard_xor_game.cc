class Solution {
    public:
        bool xorGame(vector<int>& nums) {
            int sum = 0;
            for (auto n : nums) {
                sum ^= n;
            }
    
            return sum == 0 || nums.size() % 2 == 0;
        }
    };
    // Time: O(n)
    // Space: O(1)