class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(begin(clips), end(clips));

        int ans = 0;
        int n = clips.size();
        for (int i = 0, st = 0, end = 0; st < time; st = end, ++ans) {
            while (i < n && clips[i][0] <= st) {
                end = max(end, clips[i++][1]);
            }

            if (st == end) {
                return -1;
            }
        }

        return ans;
    }
};
// 0 ms
// 10.47 MB

