class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            int sum = accumulate(begin(nums), end(nums), 0);
    
            return sum % k;
        }
    };
    // Time: O(n)
    // Space: O(1)