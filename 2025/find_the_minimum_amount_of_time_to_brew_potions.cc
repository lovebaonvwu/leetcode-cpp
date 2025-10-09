class Solution
{
public:
    long long minTime(vector<int> &skill, vector<int> &mana)
    {
        int n = skill.size();
        int m = mana.size();

        vector<long long> endTime(n);

        for (int i = 0; i < m; ++i)
        {
            long long time = 0;
            long long maxDiff = 0;

            for (int j = 0; j < n; ++j)
            {
                maxDiff = max(maxDiff, endTime[j] - time);
                time += 1LL * skill[j] * mana[i];
                endTime[j] = time;
            }

            for (int j = 0; j < n; ++j)
            {
                endTime[j] += maxDiff;
            }
        }

        return endTime.back();
    }
};
// time: O(n * m)
// space: O(n)