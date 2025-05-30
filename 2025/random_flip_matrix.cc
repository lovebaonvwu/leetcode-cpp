class Solution
{
    unordered_map<int, int> mp;
    int nr;
    int nc;
    int rem;

    mt19937 rng{random_device{}()};

    int randint(int bound)
    {
        uniform_int_distribution<int> uni(0, bound);

        return uni(rng);
    }

public:
    Solution(int m, int n) : nr(m), nc(n), rem(nr * nc)
    {
    }

    vector<int> flip()
    {
        int r = randint(--rem);
        if (mp.find(r) == mp.end())
        {
            mp[r] = r;
        }

        int x = mp[r];

        if (mp.find(rem) == mp.end())
        {
            mp[rem] = rem;
        }

        mp[r] = mp[rem];

        return {x / nc, x % nc};
    }

    void reset()
    {
        mp.clear();
        rem = nr * nc;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
// Time: O(1) for flip and reset
// Space: O(m * n) for storing the mapping of flipped indices