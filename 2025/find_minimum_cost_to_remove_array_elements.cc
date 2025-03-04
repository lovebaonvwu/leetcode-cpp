class Solution {
    public:
        int minCost(vector<int>& nums) {
            if (nums.size() < 3) {
                return *max_element(begin(nums), end(nums));
            }
    
            vector<int> tmp1(nums.begin() + 3, nums.end());
            vector<int> tmp2(nums.begin() + 3, nums.end());
            sort(nums.begin(), nums.begin() + 3);
    
            tmp1.insert(tmp1.begin(), nums[2]);
            tmp2.insert(tmp2.begin(), nums[0]);
    
    
            return min(nums[1] + minCost(tmp1), nums[2] + minCost(tmp2));
        }
    };
    // Memory Limit Exceeded

class Solution {
    public:
    int minCost(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> cached(n, vector<int>(n, -1));
        
            function<int(int, int)> dfs = [&](int i, int j) -> int {
                if (j == n) {
                    return nums[i];
                }
        
                if (j == n - 1) {
                    return max(nums[i], nums[j]);
                }
        
                if (cached[i][j] != -1) {
                    return cached[i][j];
                }
        
                int ret0 = max(nums[i], nums[j]) + dfs(j + 1, j + 2);
                int ret1 = max(nums[i], nums[j + 1]) + dfs(j, j + 2);
                int ret2 = max(nums[j], nums[j + 1]) + dfs(i, j + 2);
        
                return cached[i][j] = min({ret0, ret1, ret2});
            };
        
        return dfs(0, 1);
    }
};

        // 629 ms
