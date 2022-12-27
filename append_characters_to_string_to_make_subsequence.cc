class Solution 
{
public:
    int appendCharacters(string s, string t) 
    {
        int j = 0;
        for (int i = 0; i < s.size() && j < t.size(); ++i)
        {
            if (s[i] == t[j])
            {
                ++j;
            }
        }

        return t.size() - j;
    }
};
// Runtime 17 ms
// Memory 10.6 MB
// 2022.12.27 at 奥盛大厦