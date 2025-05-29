class Solution
{
    const int mod = 1337;

    int quick_pow(int base, int e)
    {
        int ret = 1;

        base %= mod;

        while (e > 0)
        {
            if (e & 1)
            {
                ret = (ret * base) % mod;
            }

            base = (base * base) % mod;

            e >>= 1;
        }

        return ret;
    }

public:
    int superPow(int a, vector<int> &b)
    {
        if (b.empty())
        {
            return 1;
        }

        int n = b.back();
        b.pop_back();

        return quick_pow(superPow(a, b), 10) * quick_pow(a, n) % mod;
    }
};
// Time: O(log(n))
// Space: O(log(n))