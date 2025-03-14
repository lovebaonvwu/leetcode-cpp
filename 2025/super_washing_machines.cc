class Solution {
    public:
        int findMinMoves(vector<int>& machines) {
            int sum = accumulate(begin(machines), end(machines), 0);
            int n = machines.size();
    
            if (sum % n != 0) {
                return -1;
            }
    
            int t = sum / n;
    
            int prev = 0;
            int ans = 0;
            for (auto m : machines) {
                prev += m - t;
                ans = max(ans, max(m - t, abs(prev)));
            }
    
            return ans;
        }
    };
    // 0 ms
    // 16.84 MB

