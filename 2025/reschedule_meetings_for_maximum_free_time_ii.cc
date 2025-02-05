class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();

        vector<int> pre(n + 1);
        vector<int> suf(n + 1);

        for (int i = 0, prev = 0; i < n; ++i) {
            int gap = startTime[i] - prev;
            pre[i + 1] = max(pre[i], gap);
            prev = endTime[i];
        }

        for (int i = n - 1, prev = eventTime; i >= 0; --i) {
            int gap = prev - endTime[i];
            suf[i] = max(suf[i + 1], gap);
            prev = startTime[i];
        }

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            int start = i == 0 ? 0 : endTime[i - 1];
            int end = i == n - 1 ? eventTime : startTime[i + 1];

            if (pre[i] >= (endTime[i] - startTime[i]) || suf[i + 1] >= (endTime[i] - startTime[i])) {
                ans = max(ans, end - start);
            } else {
                ans = max(ans, end - start - (endTime[i] - startTime[i]));
            }
        }

        return ans;
    }
};
// 11 ms
// 144.83 MB

