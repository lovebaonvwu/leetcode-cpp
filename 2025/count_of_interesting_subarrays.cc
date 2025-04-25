class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            int n = nums.size();
    
            unordered_map<int, int> mp;
            mp[0] = 1;
    
            long long ans = 0;
            int cnt = 0;
    
            for (auto num : nums) {
                cnt += (num % modulo == k);
    
                int cur = cnt % modulo;
                int target = (cur - k + modulo) % modulo;
    
                ans += mp[target];
                ++mp[cur];
            }
    
            return ans;
        }
    };
    // Time: O(n)
    // Space: O(n)