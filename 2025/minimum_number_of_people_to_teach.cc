class Solution
{
public:
    int minimumTeachings(int n, vector<vector<int>> &languages, vector<vector<int>> &friendships)
    {
        unordered_set<int> users;

        for (auto &f : friendships)
        {
            unordered_map<int, int> mp;
            bool canCommunicate = false;

            for (auto lan : languages[f[0] - 1])
            {
                mp[lan] = 1;
            }

            for (auto lan : languages[f[1] - 1])
            {
                if (mp[lan])
                {
                    canCommunicate = true;
                    break;
                }
            }

            if (!canCommunicate)
            {
                users.insert(f[0] - 1);
                users.insert(f[1] - 1);
            }
        }

        int max_cnt = 0;
        vector<int> cnt(n + 1, 0);
        for (auto &user : users)
        {
            for (auto &lan : languages[user])
            {
                ++cnt[lan];
                max_cnt = max(max_cnt, cnt[lan]);
            }
        }

        return users.size() - max_cnt;
    }
};
// Time: O(f * l) where f is the number of friendships and l is the average number of languages per user
// Space: O(u + n) where u is the number of users in friendships and n