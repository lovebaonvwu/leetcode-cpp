class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        unordered_map<string, int> mp;
        int n = s.size();
        int m = n / k;
        for (int i = 0; i < n; i += m) {
            ++mp[s.substr(i, m)];
        }

        for (int i = 0; i < n; i += m) {
            string partial = t.substr(i, m);

            if (mp[partial] < 1) {
                return false;
            }

            --mp[partial];
        }

        return true;
    }
};
// 217 ms
// 68.39 MB
