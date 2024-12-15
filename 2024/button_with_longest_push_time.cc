class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {

        int ans = events[0][0];
        int maxt = events[0][1];
        for (int i = 1; i < events.size(); ++i) {
            if (events[i][1] - events[i - 1][1] > maxt) {
                maxt = events[i][1] - events[i - 1][1];
                ans = events[i][0];
            } else if (events[i][1] - events[i - 1][1] == maxt) {
                ans = min(ans, events[i][0]);
            }
        }

        return ans;
    }
};
// 0 ms
// 26.49 MB

