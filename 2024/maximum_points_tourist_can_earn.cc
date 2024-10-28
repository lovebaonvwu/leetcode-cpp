class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        vector<vector<int>> cached(k, vector<int>(n, -1));

        function<int(int, int)> dfs = [&](int day, int city) -> int {
            if (day == k) {
                return 0;
            }

            if (cached[day][city] != -1) {
                return cached[day][city];
            }

            int stay_score = stayScore[day][city] + dfs(day + 1, city);
            int travel_score = 0;
            for (int dest = 0; dest < n; ++dest) {
                travel_score = max(travel_score, travelScore[city][dest] + dfs(day + 1, dest));
            }

            return cached[day][city] = max(stay_score, travel_score);
        };

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, dfs(0, i));
        }

        return ans;
    }
};
// 1462 ms
// 58.70 MB
