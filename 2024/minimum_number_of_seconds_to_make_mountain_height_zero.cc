class Solution {

    bool valid(const vector<int>& workerTimes, long long target, int mountainHeight) {
        long long cnt = 0;
        for (long long time : workerTimes) {
            int lo = 0;
            int hi = mountainHeight;

            while (lo < hi) {
                int md = (lo + hi + 1) / 2;
                if (time * (1 + md) * md > target * 2) {
                    hi = md - 1;
                } else {
                    lo = md;
                }
            }

            cnt += lo;

            if (cnt >= mountainHeight) {
                return true;
            }
        }

        return false;
    }
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int mostInefficientWorker = *max_element(begin(workerTimes), end(workerTimes));
        long long lo = 1;
        long long hi = 1e16;

        while (lo < hi) {
            long long md = (lo + hi) / 2;
            if (valid(workerTimes, md, mountainHeight)) {
                hi = md;
            } else {
                lo = md + 1;
            }
        }

        return lo;
    }
};
// 70 ms
// 27.90 MB
