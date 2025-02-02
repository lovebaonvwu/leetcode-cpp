class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gap;
        int n = startTime.size();

        for (int i = 0, prevEnd = 0; i < n; ++i) {
            gap.push_back(startTime[i] - prevEnd);
            prevEnd = endTime[i];
        }

        gap.push_back(eventTime - endTime.back());

        int ans = 0;
        for (int i = 0, sum = 0; i < gap.size(); ++i) {
            sum += gap[i];

            if (i >= k + 1) {
                sum -= gap[i - (k + 1)];
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};
// 0 ms
// 125.78 MB
