class Solution {
    public:
        int countGoodNumbers(long long n) {
    
            int mod = 1e9 + 7;
    
            auto quickmul = [mod](long long base, long long exp) -> int {
                long long ret = 1;
                while (exp > 0) {
                    if (exp & 1) {
                        ret = ret * base % mod;
                    }
                    base = base * base % mod;
    
                    exp /= 2;
                }
    
                return ret;
            };
    
            long long odd = quickmul(4, n / 2);
            long long even = quickmul(5, (n + 1) / 2);
    
            return (odd * even) % mod;
        }
    };
    // Time: O(log n)
    // Space: O(1)
    // n: number of digits