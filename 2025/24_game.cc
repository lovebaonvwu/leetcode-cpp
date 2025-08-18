class Solution
{
public:
    bool judgePoint24(vector<int> &cards)
    {
        vector<double> nums;
        for (auto card : cards)
        {
            nums.push_back(card);
        }

        sort(begin(nums), end(nums));

        while (true)
        {
            unordered_set<double> rets = helper(nums, 0, 3);
            for (auto ret : rets)
            {
                if (abs(ret - 24.0) < 1e-9)
                {
                    return true;
                }
            }

            if (next_permutation(begin(nums), end(nums)) == false)
            {
                break;
            }
        }

        return false;
    }

    unordered_set<double> helper(const vector<double> &nums, int start, int end)
    {
        if (start == end)
        {
            return {nums[start]};
        }

        unordered_set<double> rets;

        for (int i = start; i < end; ++i)
        {
            unordered_set<double> A = helper(nums, start, i);
            unordered_set<double> B = helper(nums, i + 1, end);

            for (auto a : A)
            {
                for (auto b : B)
                {
                    rets.insert(a + b);
                    rets.insert(a - b);
                    rets.insert(a * b);
                    if (b != 0)
                    {
                        rets.insert(a / b);
                    }
                }
            }
        }

        return rets;
    }
};
// Time: O(n!)
// Space: O(n!)