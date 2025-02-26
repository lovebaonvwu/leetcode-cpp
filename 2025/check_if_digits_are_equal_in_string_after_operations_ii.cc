class Solution {

    int C(int n, int m, int p) {
        int ret = 1;
        for (int i = 0; i < m; ++i) {
            ret *= n - i;
            ret /= i + 1;
        }

        return ret;
    }

    long long Lucas(int n, int m, int p) {
        if (m == 0) {
            return 1;
        }

        return (C(n % p, m % p, p) * Lucas(n / p, m / p, p)) % p;
    }

    bool check(const string& s, int p) {
        int len = s.size();
        int n = len - 2;

        int ret1 = 0;
        for (int i = 0; i < len - 1; ++i) {
            ret1 += (s[i] - '0') * Lucas(n, i, p);
            ret1 %= p;
        }

        int ret2 = 0;
        for (int i = 1; i < len; ++i) {
            ret2 += (s[i] - '0') * Lucas(n, i - 1, p);
            ret2 %= p;
        }

        return ret1 == ret2;
    }
public:
    bool hasSameDigits(string s) {
        return check(s, 2) && check(s, 5);
    }
};
// 695 ms
// 18.36 MB
