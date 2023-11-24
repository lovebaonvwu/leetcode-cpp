class Solution 
{
public:
    string toHexspeak(string num) 
    {
        char ch[16] = {'O', 'I', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

        long long n = stoll(num);
        string hex = "";

        while (n > 0)
        {
            char c = ch[n % 16];
            if (c >= '2' && c <= '9')
            {
                return "ERROR";
            }

            hex = c + hex;

            n /= 16;
        }

        return hex;
    }
};
// Runtime 4 ms
// Memory 5.8 MB
// 2022.12.15 at 奥盛大厦