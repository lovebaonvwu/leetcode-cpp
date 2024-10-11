class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();

        vector<int> friends(n);
        iota(begin(friends), end(friends), 0);
        sort(begin(friends), end(friends), [&](auto& a, auto& b) {
            return times[a][0] < times[b][0];
        });

        priority_queue<int, vector<int>, greater<int>> chairs;
        for (int i = 0; i < n; ++i) {
            chairs.push(i);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupied;
        for (auto currentFriend : friends) {
            int currentTime = times[currentFriend][0];
            int leavingTime = times[currentFriend][1];

            while (!occupied.empty() && occupied.top().first <= currentTime) {
                auto [_, chair] = occupied.top();
                occupied.pop();

                chairs.push(chair);
            }

            auto chair = chairs.top();
            chairs.pop();

            if (currentFriend == targetFriend) {
                return chair;
            }

            occupied.push({leavingTime, chair});
        }

        return -1;
    }
};
// 131 ms
// 58.02 MB