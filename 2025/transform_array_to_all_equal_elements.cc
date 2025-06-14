class Solution
{
public:
    bool canMakeEqual(vector<int> &nums, int k)
    {
        int n = nums.size();

        auto tmp = nums;

        int cnt = k;
        for (int i = 0; i < n - 1 && cnt > 0; ++i)
        {
            if (tmp[i] == 1)
            {
                tmp[i] *= -1;
                tmp[i + 1] *= -1;
                --cnt;
            }
        }

        if (all_of(begin(tmp), end(tmp), [](auto x)
                   { return x == -1; }) &&
            cnt >= 0)
        {
            return true;
        }

        cnt = k;
        tmp = nums;
        for (int i = 0; i < n - 1 && cnt > 0; ++i)
        {
            if (tmp[i] == -1)
            {
                tmp[i] *= -1;
                tmp[i + 1] *= -1;
                --cnt;
            }
        }

        if (all_of(begin(tmp), end(tmp), [](auto x)
                   { return x == 1; }) &&
            cnt >= 0)
        {
            return true;
        }

        return false;
    }
};
// Time: O(n)
// Space: O(1)