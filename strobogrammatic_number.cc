class Solution 
{
public:
    bool isStrobogrammatic(string num) 
    {
        string result;
        for (int i = num.size() - 1; i >= 0; --i)
        {
            if (num[i] == '9')
            {
                result += '6';
            }
            else if (num[i] == '6')
            {
                result += '9';
            }
            else if (num[i] == '0' || num[i] == '1' || num[i] == '8')
            {
                result += num[i];
            }
        }

        return result == num;
    }
};
// Runtime 2 ms
// Memory 6 MB
// 2022.12.20 at 奥盛大厦