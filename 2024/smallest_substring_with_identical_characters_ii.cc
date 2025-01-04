class Solution {

    bool valid(const string& s, const vector<int>& nums, int md, int ops) {
        if (md == 1) {
            int even = 0;
            int odd = 0;

            for (int i = 0; i < s.size(); ++i) {
                if ((s[i] - '0') != i % 2) {
                    ++even;
                }

                if ((s[i] - '0') == i % 2) {
                    ++odd;
                }
            }

            return min(odd, even) <= ops;
        }

        int sum = 0;
        for (auto num : nums) {
            sum += (num) / (md + 1);
        }

        return sum <= ops;
    }
public:
    int minLength(string s, int numOps) {
        int n = s.size();

        vector<int> cnt;
        char prev = s[0];
        for (int i = 0, j = 0; j < n; ++j) {
            while (j < n && s[j] == s[i]) {
                ++j;
            }

            cnt.push_back(j - i);
            i = j;
        }

        int lo = 1;
        int hi = n;

        while (lo < hi) {
            int md = (lo + hi) / 2;
            if (valid(s, cnt, md, numOps)) {
                hi = md;
            } else {
                lo = md + 1;
            }
        }

        return lo;
    }
};
// 12 ms
// 22.18 MB
