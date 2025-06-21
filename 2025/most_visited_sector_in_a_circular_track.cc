class Solution
{
public:
    vector<int> mostVisited(int n, vector<int> &rounds)
    {
        vector<int> cnt(n + 1);

        for (int i = 1; i < rounds.size(); ++i)
        {
            int start = rounds[i - 1];
            int end = rounds[i];

            if (end < start)
            {
                end += (n + 1);
            }

            start += (i > 1 ? 1 : 0);
            for (int j = start; j <= end; ++j)
            {
                ++cnt[j % (n + 1)];
            }
        }

        int max_visited = *max_element(begin(cnt), end(cnt));

        vector<int> ans;

        for (int i = 1; i < cnt.size(); ++i)
        {
            if (cnt[i] == max_visited)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
// Time: O(n * m), where n is the number of sectors and m is the number of rounds
// Space: O(n)