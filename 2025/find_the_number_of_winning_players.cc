class Solution
{
public:
    int winningPlayerCount(int n, vector<vector<int>> &pick)
    {
        unordered_map<int, unordered_map<int, int>> mp;

        for (auto &p : pick)
        {
            ++mp[p[0]][p[1]];
        }

        int ans = 0;

        for (auto &[player, balls] : mp)
        {
            for (auto [_, count] : balls)
            {
                if (count > player)
                {
                    ++ans;
                    break;
                }
            }
        }

        return ans;
    }
};
// Time: O(n^2)
// Space: O(n^2)