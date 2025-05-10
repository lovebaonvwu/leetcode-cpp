class Solution
{
public:
    int maxProduct(int n)
    {
        vector<int> digits;

        while (n > 0)
        {
            digits.push_back(n % 10);
            n /= 10;
        }

        sort(rbegin(digits), rend(digits));

        return digits[0] * digits[1];
    }
};
// Time: O(nlog n)
// Space: O(n)
// n: number of digits in n