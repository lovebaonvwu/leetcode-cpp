class Solution {
    public:
        int largestInteger(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> cnt(51);
            for (int i = 0; i < k; ++i) {
                ++cnt[nums[i]];
            }
    
            vector<int> visited(51);
            for (int i = 0; i < 51; ++i) {
                if (cnt[i] > 0) {
                    ++visited[i];
                }
            }
    
            for (int i = k; i < n; ++i) {
                ++cnt[nums[i]];
                --cnt[nums[i - k]];
                for (int i = 0; i < 51; ++i) {
                    if (cnt[i] > 0) {
                        ++visited[i];
                    }
                }
            }
    
            int ans = -1;
            for (int i = 0; i < 51; ++i) {
                if (visited[i] == 1) {
                    ans = max(ans, i);
                }
            }
    
            return ans;
        }
    };
    // 1 ms
    // 29.21 MB

