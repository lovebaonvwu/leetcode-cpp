class Solution
{
public:
    bool checkDivisibility(int n)
    {
        int sum = 0;
        int product = 1;

        int x = n;
        while (x > 0)
        {
            sum += x % 10;
            product *= x % 10;

            x /= 10;
        }

        return n % (sum + product) == 0;
    }
};
// Time: O(n)
// Space: O(1)