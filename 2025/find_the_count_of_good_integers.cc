class Solution {
    public:
        long long countGoodIntegers(int n, int k) {
            int base = pow(10, (n - 1) / 2);
            unordered_set<string> dict;
            int skip = n & 1;
    
            for (int i = base; i < base * 10; ++i) {
                string s = to_string(i);
                s += string(s.rbegin() + skip, s.rend());
                long long num = stoll(s);
    
                if (num % k == 0) {
                    sort(s.begin(), s.end());
                    dict.insert(s);
                }
            }
    
            vector<long long> factorial(n + 1, 1);
            for (int i = 1; i <= n; ++i) {
                factorial[i] = factorial[i - 1] * i;
            }
    
            long long ans = 0;
            for (auto& s : dict) {
                vector<int> cnt(10);
                for (auto ch : s) {
                    ++cnt[ch - '0'];
                }
    
                long long total = 1;
                total = (n - cnt[0]) * factorial[n - 1];
                for (auto c : cnt) {
                    total /= factorial[c];
                }
    
                ans += total;
            }
    
            return ans;
        }
    };
    // Time: O(nlogn * 10^(n / 2))
    // Space: O(n*10^(n / 2))
    // n: number of digits
    // k: divisor