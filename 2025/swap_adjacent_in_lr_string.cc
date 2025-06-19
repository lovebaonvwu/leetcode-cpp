class Solution
{
public:
    bool canTransform(string start, string result)
    {
        int i = 0;
        int j = 0;

        int n = start.size();

        while (i < n && j < n)
        {
            while (i < n && start[i] == 'X')
            {
                ++i;
            }
            while (j < n && result[j] == 'X')
            {
                ++j;
            }

            if (i == n || j == n)
            {
                break;
            }

            if (start[i] != result[j])
            {
                return false;
            }

            if (start[i] == 'L' && i < j)
            {
                return false;
            }

            if (start[i] == 'R' && i > j)
            {
                return false;
            }

            ++i;
            ++j;
        }

        while (i < n && start[i] == 'X')
        {
            ++i;
        }

        while (j < n && result[j] == 'X')
        {
            ++j;
        }

        return i == n && j == n;
    }
};
// Time: O(n)
// Space: O(1)