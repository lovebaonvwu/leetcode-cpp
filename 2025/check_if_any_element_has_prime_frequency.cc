class Solution
{
    vector<int> buildPrimes(int n)
    {
        vector<bool> isPrimes(n + 1, true);

        isPrimes[0] = false;
        isPrimes[1] = false;

        for (int i = 2; i * i <= n; ++i)
        {
            if (isPrimes[i])
            {
                for (int j = i * i; j <= n; j += i)
                {
                    isPrimes[j] = false;
                }
            }
        }

        vector<int> ret;
        for (int i = 0; i <= n; ++i)
        {
            if (isPrimes[i])
            {
                ret.push_back(i);
            }
        }

        return ret;
    }

public:
    bool checkPrimeFrequency(vector<int> &nums)
    {
        vector<int> primes = buildPrimes(100);

        unordered_set<int> st(begin(primes), end(primes));

        unordered_map<int, int> cnt;
        for (auto n : nums)
        {
            ++cnt[n];
        }

        for (auto [_, c] : cnt)
        {
            if (st.find(c) != st.end())
            {
                return true;
            }
        }

        return false;
    }
};

// Time: O(n + log(m))
// Space: O(m)