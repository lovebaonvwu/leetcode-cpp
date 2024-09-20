class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int n = removable.size();

        int lo = -1;
        int hi = n - 1;

        function<bool(int)> check = [&](int k) -> bool {
            unordered_set<int> removed(removable.begin(), removable.begin() + k + 1);
            int i = 0;
            int j = 0;
            while (i < s.size() && j < p.size()) {
                if (removed.find(i) != removed.end()) {
                    ++i;
                    continue;
                }

                if (s[i] == p[j]) {
                    ++j;
                }
                ++i;
            }

            return j == p.size();
        };

        while (lo < hi) {
            int md = (lo + hi + 1) / 2;
            if (check(md)) {
                lo = md;
            } else {
                hi = md - 1;
            }
        }

        return lo + 1;
    }
};
// 1347 ms
// 388.98 MB