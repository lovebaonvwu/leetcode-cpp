class Solution {
    public:
        int maxChunksToSorted(vector<int>& arr) {
            int n = arr.size();
            vector<int> exp(arr.begin(), arr.end());
            sort(begin(exp), end(exp));
    
            unordered_map<int, int> cnt;
            int balance = 0;
            int ans = 0;
    
            for (int i = 0; i < n; ++i) {
                int x = arr[i];
                int y = exp[i];
    
                ++cnt[x];
                if (cnt[x] == 0) {
                    --balance;
                }
                if (cnt[x] == 1) {
                    ++balance;
                }
    
                --cnt[y];
                if (cnt[y] == -1) {
                    ++balance;
                }
                if (cnt[y] == 0) {
                    --balance;
                }
    
                ans += balance == 0;
            }
    
            return ans;
        }
    };
    // Time: O(log(n))
    // Space: O(n)