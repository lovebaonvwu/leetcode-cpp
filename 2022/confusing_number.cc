class Solution 
{
public:
    bool confusingNumber(int n) 
    {
        int t = n;
        int m = 0;

        while (t > 0)
        {
            int x = t % 10;
            if (x == 9)
            {
                x = 6;
            }
            else if (x == 6)
            {
                x = 9;
            }
            else if (x == 2 || x == 3 || x == 4 || x == 5 || x == 7)
            {
                return false;
            }

            m = m * 10 + x;

            t /= 10;
        }

        return m != n;
    }
};
// Runtime 0 ms
// Memory 6 MB
// 2022.12.19 at 茗筑美嘉