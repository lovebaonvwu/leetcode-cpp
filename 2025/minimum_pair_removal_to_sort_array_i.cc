class Solution {
    public:
        int minimumPairRemoval(vector<int>& nums) {
            int ans = 0;
    
            while (true) {
                int n = nums.size();
                bool ok = true;
                for (int i = 1; i < n; ++i) {
                    if (nums[i] < nums[i - 1]) {
                        ok = false;
                        break;
                    }
                }
    
                if (ok) {
                    break;
                }
    
                ++ans;
    
                int minSum = INT_MAX;
                int minIndex = -1;
                for (int i = 0; i < n - 1; ++i) {
                    if (nums[i] + nums[i + 1] < minSum) {
                        minSum = nums[i] + nums[i + 1];
                        minIndex = i;
                    }
                }
    
                vector<int> tmp;
    
                int i = 0;
                while (i < minIndex) {
                    tmp.push_back(nums[i++]);
                }
    
                tmp.push_back(nums[i] + nums[i + 1]);
                i += 2;
    
                while (i < n) {
                    tmp.push_back(nums[i++]);
                }
    
                swap(tmp, nums);
            }
    
            return ans;
        }
    };
    // Time: O(n^2)
    // Space: O(n)