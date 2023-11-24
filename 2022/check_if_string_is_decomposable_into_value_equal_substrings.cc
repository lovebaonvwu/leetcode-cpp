class Solution 
{
public:
    bool isDecomposable(string s) 
    {
        s.append(1, '*');
        int seen = 0;
        for (int i = 1, cnt = 1; i < s.size(); ++i)
        {
            if (s[i] != s[i - 1])
            {
                if (cnt % 3 != 0 && (cnt - 2) % 3 != 0)
                {
                    return false;
                }

                if (seen && cnt % 3 != 0)
                {
                    return false;
                }

                if ((cnt - 2) % 3 == 0)
                {
                    seen = 1;
                }
                cnt = 1;
            }
            else
            {
                ++cnt;
            }
        }

        return seen;
    }
};
// Runtime 2 ms
// Memory 6.9 MB
// 2022.12.17 at 奥盛大厦