class Solution
{
public:
    long long sumOfLargestPrimes(string s)
    {
        unordered_set<string> st;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i; j < n; ++j)
            {
                st.insert(s.substr(i, j - i + 1));
            }
        }

        set<long long> primes;
        for (auto &s : st)
        {
            long long x = stoll(s);
            bool valid = true;
            for (long long k = 2; k * k <= x; ++k)
            {
                if (x % k == 0)
                {
                    valid = false;
                    break;
                }
            }

            if (x > 1 && valid)
            {
                primes.insert(x);
            }
        }

        long long ans = 0;
        int cnt = 0;

        for (auto it = primes.rbegin(); cnt < 3 && it != primes.rend(); ++it, ++cnt)
        {
            ans += *it;
        }

        return ans;
    }
};
// Time: O(n^2 * log(n)) for generating substrings and checking primality
// Space: O(n^2) for storing substrings and O(n) for storing primes