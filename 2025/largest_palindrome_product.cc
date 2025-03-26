class Solution {
    public:
        int largestPalindrome(int n) {
            if (n == 1) {
                return 9;
            }
    
            int low = pow(10, n - 1);
            int high = pow(10, n) - 1;
    
            for (int i = high; i >= low; --i) {
                long long p = build(i);
    
                for (int j = high; j >= sqrt(p); --j) {
                    if (p % j == 0 && (p / j >= low)) {
                        return p % 1337;
                    }
                }
            }
    
            return -1;
        }
    
        long long build(int i) {
            string s = to_string(i);
            reverse(begin(s), end(s));
    
            return stoll(to_string(i) + s);
        }
    };
    // Time: O(pow(10, n) * sqrt(pow(10, n)))
    // Space: O(1)