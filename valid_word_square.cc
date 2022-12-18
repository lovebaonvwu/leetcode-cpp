class Solution 
{
public:
    bool validWordSquare(vector<string>& words) 
    {
        int m = words.size();

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < words[i].size(); ++j)
            {
                if ((words[i][j] != ' ' && j >= m) || words[i][j] != words[j][i])
                {
                    return false;
                }
            }
        }

        return true;
    }
};
// Runtime 42 ms
// Memory 8.9 MB
// 2022.12.18 at 奥盛大厦