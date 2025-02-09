class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        unordered_map<int, int> mp;

        for (int i = 0; i < elements.size(); ++i) {
            if (mp.find(elements[i]) == mp.end()) {
                mp[elements[i]] = i;
            }
        }

        vector<int> ans;

        for (auto n : groups) {
            int p = INT_MAX;
            for (int i = 1; i * i <= n; ++i) {
                if (n % i == 0 && mp.find(i) != mp.end()) {
                    p = min(p, mp[i]);
                }

                if (n % i == 0 && mp.find(n / i) != mp.end()) {
                    p = min(p, mp[n / i]);
                }
            }

            ans.push_back((p == INT_MAX ? -1 : p));
        }

        return ans;
    }
};
// 1163 ms
// 252.95 MB
