class Solution {
    public:
        int oddEvenJumps(vector<int>& arr) {
            int n = arr.size();
            vector<bool> odd(n);
            vector<bool> even(n);
    
            map<int, int> pos;
            pos[arr.back()] = n - 1;
            odd[n - 1] = true;
            even[n - 1] = true;
    
            int ans = 1;
    
            for (int i = n - 2; i >= 0; --i) {
                auto it = pos.lower_bound(arr[i]);
                if (it != pos.end()) {
                    odd[i] = even[it->second];
                }
    
                it = pos.upper_bound(arr[i]);
                if (it != pos.begin()) {
                    it = prev(it);
                    even[i] = odd[it->second];
                }
    
                ans += odd[i];
    
                pos[arr[i]] = i;
            }
    
            return ans;
        }
    };
    // Time: O(n * log n)
    // Space: O(n)
    // n: number of elements in arr