class Solution
{
public:
    int minDeletion(string s, int k)
    {
        vector<int> cnt(26);

        for (auto ch : s)
        {
            ++cnt[ch - 'a'];
        }

        sort(begin(cnt), end(cnt));

        int ans = 0;

        for (int i = 0; i < 26 && 26 - i > k; ++i)
        {
            ans += cnt[i];
        }

        return ans;
    }
};
// Time: O(N)
// Space: O(1)