class Solution 
{
public:
    bool makePalindrome(string s) 
    {
        int i = 0, j = s.size() - 1;
        int cnt = 2;
        while (i < j)
        {
            if (s[i++] != s[j--])
            {
                --cnt;
                if (cnt < 0)
                {
                    return false;
                }
            }
        }

        return true;
    }
};
// Runtime 26 ms
// Memory 8.2 MB
// 2022.12.12 at 奥盛大厦