class Solution
{
public:
    int countPermutations(vector<int> &complexity)
    {
        long long ans = 1;
        int mod = 1e9 + 7;

        for (int i = 1; i < complexity.size(); ++i)
        {
            if (complexity[i] <= complexity[0])
            {
                return 0;
            }

            ans *= i;
            ans %= mod;
        }

        return ans;
    }
};
// Time: O(n)
// Space: O(1)