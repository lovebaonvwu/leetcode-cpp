class Solution
{
public:
    int smallestIndex(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            int sum = 0;
            int n = nums[i];

            while (n > 0)
            {
                sum += n % 10;
                n /= 10;
            }

            if (sum == i)
            {
                return i;
            }
        }
        return -1;
    }
};
// Time: O(n)
// Space: O(1)