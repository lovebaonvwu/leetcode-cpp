class Solution 
{
public:
    int countLetters(string s) 
    {
        int ans = 1;
        for (int i = 1, cnt = 1; i < s.size(); ++i)
        {
            cnt = s[i] == s[i - 1] ? cnt + 1 : 1;
            ans += cnt;
        }

        return ans;
    }
};
// Runtime 0 ms
// Memory 6.4 MB
// 2022.12.11 at 茗筑美嘉