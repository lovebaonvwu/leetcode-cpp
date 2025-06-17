class Solution
{
    const static int mod = 1e9 + 7;
    const static int mx = 1e5;

    long long fact[mx];
    long long inv_fact[mx];

    long long quick_pow(long long base, int e)
    {
        long long ret = 1;

        while (e > 0)
        {
            if (e & 1)
            {
                ret = ret * base % mod;
            }

            base = base * base % mod;

            e >>= 1;
        }

        return ret;
    }

    long long comb(int n, int m)
    {
        return fact[n] * inv_fact[m] % mod * inv_fact[n - m] % mod;
    }

    void init()
    {
        if (fact[0])
        {
            return;
        }

        fact[0] = 1;
        for (int i = 1; i < mx; ++i)
        {
            fact[i] = fact[i - 1] * i % mod;
        }

        inv_fact[mx - 1] = quick_pow(fact[mx - 1], mod - 2);
        for (int i = mx - 1; i > 0; --i)
        {
            inv_fact[i - 1] = inv_fact[i] * i % mod;
        }
    }

public:
    int countGoodArrays(int n, int m, int k)
    {
        init();

        return comb(n - 1, k) * m % mod * quick_pow(m - 1, n - k - 1) % mod;
    }
};
// Time: O(n)
// Space: O(n)