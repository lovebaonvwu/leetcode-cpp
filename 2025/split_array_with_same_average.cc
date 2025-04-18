class Solution {
    public:
        bool splitArraySameAverage(vector<int>& nums) {
            int n = nums.size();
    
            function<bool(int, int, int, int, int)> dfs = [&](int i, int lsum, int lsize, int rsum, int rsize) -> bool {
                if (i == n) {
                    return lsize > 0 && rsize > 0 && lsum * rsize == lsize * rsum;
                }
    
                return dfs(i + 1, lsum + nums[i], lsize + 1, rsum, rsize) || 
                        dfs(i + 1, lsum, lsize, rsum + nums[i], rsize + 1);
            };
    
            return dfs(0, 0, 0, 0, 0);
        }
    };
    // Time: O(2^n)
    // Space: O(n)

    class Solution {
        public:
            bool splitArraySameAverage(vector<int>& nums) {
                int n = nums.size();
                int total = accumulate(begin(nums), end(nums), 0);
        
                vector<vector<bool>> dp(n + 1, vector<bool>(total + 1));
                dp[0][0] = true;
        
                int cursum = 0;
        
                for (auto val : nums) {
                    cursum += val;
        
                    for (int num = n / 2 + 1; num >= 1; --num) {
                        for (int sum = cursum; sum >= val; --sum) {
                            if (dp[num - 1][sum - val]) {
                                dp[num][sum] = true;
                                if (num != n && sum * n == total * num) {
                                    return true;
                                }
                            }
                        }
                    }
                }
        
                return false;
            }
        };

        // Time: O(n*sum*n)
        // Space: O(sum*n)