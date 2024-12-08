class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(begin(events), end(events));

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int prevMax = 0;
        int ans = 0;
        for (auto& e : events) {
            while (!pq.empty() && pq.top().first < e[0]) {
                prevMax = max(prevMax, pq.top().second);
                pq.pop();
            }

            ans = max(ans, prevMax + e[2]);
            pq.push({e[1], e[2]});
        }

        return ans;
    }
};
// 60 ms
// 125.96 MB