class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        priority_queue<array<int, 4>, vector<array<int, 4>>, greater<>> pq;
        pq.push({0, 0, 0, 1});
        vector<vector<int>> arriveAt(n, vector<int>(m, INT_MAX));
        arriveAt[0][0] = 0;

        int dirs[] = {0, 1, 0, -1, 0};
        while (!pq.empty()) {
            auto [curTime, y, x, take] = pq.top();
            pq.pop();

            if (y == n - 1 && x == m - 1) {
                return curTime;
            }

            for (int k = 0; k < 4; ++k) {
                int dy = y + dirs[k];
                int dx = x + dirs[k + 1];

                if (dy < 0 || dy == n || dx < 0 || dx == m) {
                    continue;
                }

                int newTime = max(moveTime[dy][dx], curTime) + take;
                if (newTime < arriveAt[dy][dx]) {
                    arriveAt[dy][dx] = newTime;
                    pq.push({newTime, dy, dx, take == 1 ? 2 : 1});
                }
            }
        }

        return -1;
    }
};
// 311 ms
// 95.69 MB