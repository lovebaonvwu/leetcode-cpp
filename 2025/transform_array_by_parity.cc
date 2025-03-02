class Solution {
    public:
        vector<int> transformArray(vector<int>& nums) {
            int n = nums.size();
            int cnt = 0;
            for (auto num : nums) {
                if (num % 2 == 1) {
                    ++cnt;
                }
            }
    
            vector<int> ans(n);
            for (int i = n - 1; i >= 0 && cnt > 0; --i, --cnt) {
                ans[i] = 1;
            }
    
            return ans;
        }
    };
    // 0 ms
    // 28.39 MB

