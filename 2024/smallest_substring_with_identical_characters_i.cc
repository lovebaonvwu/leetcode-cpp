class Solution {
    bool valid(const vector<int>& cnt, const string& s, int ops, int md) {


        int total = 0;
        if (md == 1) {
            int odd = 0;
            int even = 0;
            for (int i = 0; i < s.size(); ++i) {
                if ((s[i] - '0') == i % 2) {
                    ++odd;
                }

                if ((s[i] - '0') != i % 2) {
                    ++even;
                }
            }

            total = min(odd, even);

            return total <= ops;
        }

        for (auto c : cnt) {
            total += (c - md + md + 1 - 1) / (md + 1);
        }

        return total <= ops;
    }

public:
    int minLength(string s, int numOps) {
        int n = s.size();
        int lo = 1;
        int hi = n;

        vector<int> cnt;
        char prev = s[0];
        for (int i = 0, j = 0; j < n; ++j) {
            while (j < n && s[j] == s[i]) {
                ++j;
            }

            cnt.push_back(j - i);
            i = j;
        }

        while (lo < hi) {
            int md = (lo + hi) / 2;
            if (valid(cnt, s, numOps, md)) {
                hi = md;
            } else {
                lo = md + 1;
            }
        }
        
        return lo;
    }
};
// 0 ms
// 9.67 MB
