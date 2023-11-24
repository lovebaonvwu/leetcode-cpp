class Solution 
{
public:
    int pivotInteger(int n) 
    {
        int left = 0, right = (1 + n) * n / 2;
        for (int i = 1; i <= n; ++i)
        {
            left += i;
            
            if (left == right)
            {
                return i;
            }

            right -= i;
        }

        return -1;
    }
};
// Runtime 0 ms
// Memory 6 MB
// 2022.12.23 at 茗筑美嘉