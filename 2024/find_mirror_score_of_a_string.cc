class Solution {
public:
    long long calculateScore(string s) {
        long long ans = 0;
        vector<vector<int>> mp(26);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int mirror = (25 - (s[i] - 'a'));
            if (!mp[mirror].empty()) {
                ans += (i - mp[mirror].back());
                mp[mirror].pop_back();
            } else {
                mp[s[i] - 'a'].push_back(i);
            }
        }

        return ans;
    }
};
// 12 ms
// 16.56 MB
