class Solution {
    public:
        int maxSum(vector<int>& nums) {
            set<int> st(begin(nums), end(nums));
    
            int ans = INT_MIN;
            int sum = INT_MIN / 2;
            for (auto n : st) {
                sum = max(n, sum + n);
                ans = max(ans, sum);
            }
    
            return ans;
        }
    };
    // 3 ms
    // 29.71 MB