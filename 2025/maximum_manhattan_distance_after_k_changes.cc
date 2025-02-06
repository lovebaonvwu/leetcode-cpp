class Solution {
public:
    int maxDistance(string s, int k) {
        unordered_map<char, int> cnt;
        int n = s.size();

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ++cnt[s[i]];

            int cur = min(i + 1, abs(cnt['N'] - cnt['S']) + abs(cnt['E'] - cnt['W']) + 2 * k);
            ans = max(ans, cur);
        }

        return ans;
    }
};
// 229 ms
// 38.81 MB
