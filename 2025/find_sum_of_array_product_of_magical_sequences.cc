class Solution
{
    const int MOD = 1e9 + 7;

public:
    int magicalSum(int m, int k, vector<int> &nums)
    {
        int n = nums.size();
        // The maximum possible carry won't exceed m, so m+1 is a safe upper bound.
        memo.resize(n + 1, vector<vector<vector<long long>>>(m + 1, vector<vector<long long>>(k + 1, vector<long long>(m + 1, -1))));

        // Precompute powers and combinations to avoid re-calculation
        precompute_powers(nums, m);
        precompute_combinations(m);

        return solve(0, m, k, 0, nums);
    }

private:
    vector<vector<vector<vector<long long>>>> memo;
    vector<vector<long long>> powers;
    vector<vector<long long>> combinations;

    // Precomputes nums[i]^j % MOD
    void precompute_powers(const vector<int> &nums, int m)
    {
        int n = nums.size();
        powers.resize(n, vector<long long>(m + 1));
        for (int i = 0; i < n; ++i)
        {
            powers[i][0] = 1;
            for (int j = 1; j <= m; ++j)
            {
                powers[i][j] = (powers[i][j - 1] * nums[i]) % MOD;
            }
        }
    }

    // Precomputes combinations C(n, r) % MOD
    void precompute_combinations(int m)
    {
        combinations.resize(m + 1, vector<long long>(m + 1, 0));
        for (int i = 0; i <= m; ++i)
        {
            combinations[i][0] = 1;
            for (int j = 1; j <= i; ++j)
            {
                combinations[i][j] = (combinations[i - 1][j - 1] + combinations[i - 1][j]) % MOD;
            }
        }
    }

    long long solve(int idx, int m_rem, int k_rem, int carry, const vector<int> &nums)
    {
        // Pruning: if we've already exceeded the required set bits, this path is invalid.
        if (k_rem < 0)
        {
            return 0;
        }

        // Corrected Base Case: We've considered all numbers in nums.
        // Now, we must check if a valid sequence was formed.
        if (idx == nums.size())
        {
            // A valid sequence requires us to have chosen exactly m elements (m_rem == 0)
            // and the remaining k must match the set bits in the final carry.
            if (m_rem == 0 && __builtin_popcount(carry) == k_rem)
            {
                return 1; // This combination is valid
            }
            return 0; // This combination is invalid
        }

        // Memoization check
        if (memo[idx][m_rem][k_rem][carry] != -1)
        {
            return memo[idx][m_rem][k_rem][carry];
        }

        long long ans = 0;
        // Iterate through all possible counts for the current number nums[idx]
        for (int count = 0; count <= m_rem; ++count)
        {
            int new_k_rem = k_rem - ((count + carry) % 2);
            int new_carry = (count + carry) / 2;

            long long ways = combinations[m_rem][count];
            long long prod_contrib = powers[idx][count];

            long long res_from_rest = solve(idx + 1, m_rem - count, new_k_rem, new_carry, nums);

            // If the recursive call found valid sequences, add their contribution
            if (res_from_rest > 0)
            {
                long long term = (ways * prod_contrib) % MOD;
                term = (term * res_from_rest) % MOD;
                ans = (ans + term) % MOD;
            }
        }

        return memo[idx][m_rem][k_rem][carry] = ans;
    }
};
// Time: O(n * m^2)
// Space: O(n * m^2 * log(m)) due to memoization and precomputed tables