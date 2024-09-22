class Solution {

    int countSteps(long long n, long long prefix1, long long prefix2) {
        int step = 0;
        while (prefix1 <= n) {
            step += min(n + 1, prefix2) - prefix1;
            prefix1 *= 10;
            prefix2 *= 10;
        }

        return step;
    }
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        --k;

        while (k > 0) {
            int step = countSteps(n, cur, cur + 1);
            if (step <= k) {
                k -= step;
                ++cur;
            } else {
                --k;
                cur *= 10;
            }
        }

        return cur;
    }
};
// 0 ms
// 7.5 MB