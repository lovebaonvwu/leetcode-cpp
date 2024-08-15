class Solution {
    vector<int> buildPrime(int n) {
        vector<bool> prime(n + 1, true);


        for (int i = 2; i * i <= n; ++i) {
            if (prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }

        vector<int> ret;
        for (int i = 2; i <= n; ++i) {
            if (prime[i]) {
                ret.push_back(i);
            }
        }

        return ret;
    }
public:
    int nonSpecialCount(int l, int r) {
        int n = sqrt(r) + 1;
        vector<int> primes = buildPrime(n);

        unordered_set<int> st;
        for (int p : primes) {
            st.insert(p * p);
        }

        int cnt = 0;
        for (int i = l; i <= r; ++i) {
            if (st.find(i) != st.end()) {
                ++cnt;
            }
        }

        return r - l + 1 - cnt;
    }
};
// Time Limit Exceeded

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int n = sqrt(r);
        vector<bool> prime(n + 1, true);
        vector<int> p;
        prime[0] = false;
        prime[1] = false;

        for (int i = 2; i <= n; ++i) {
            if (prime[i]) {
                p.push_back(i);

                for (int j = i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }

        int cnt = 0;
        for (int n : p) {
            if (n * n >= l && n * n <= r) {
                ++cnt;
            }
        }

        return r - l + 1 - cnt;
    }
};
// 74 ms
// 15.75 MB
