class Solution {
public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(begin(start), end(start));

        long long lo = 0;
        long long hi = start[1] + d - start[0];

        while (lo < hi) {
            long long md = (lo + hi + 1) / 2;
            int i = 1;
            long long cur = start[0];
            for (; i < start.size(); ++i) {
                cur = max(1LL * start[i], cur + md);
                if (cur > start[i] + d) {
                    break;
                }
            }

            if (i == start.size()) {
                lo = md;
            } else {
                hi = md - 1;
            }
        }

        return lo;
    }
};
// 212 ms
// 109.38 MB
