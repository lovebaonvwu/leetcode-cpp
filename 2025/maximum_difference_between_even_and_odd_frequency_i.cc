class Solution {
public:
    int maxDifference(string s) {
        unordered_map<int, int> cnt;
        for (auto c : s) {
            ++cnt[c];
        }

        int odd = 0;
        int even = INT_MAX;

        for (auto [_, c] : cnt) {
            if (c % 2 == 0) {
                even = min(even, c);
            } else {
                odd = max(odd, c);
            }
        }

        return odd - even;
    }
};
// 0 ms
// 9.90 MB
