class Solution {
 public:
  int eatenApples(vector<int>& apples, vector<int>& days) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    int ans = 0;
    int cur = 0;
    int n = days.size();

    while (cur < n || !pq.empty()) {
      if (cur < n && apples[cur] > 0) {
        pq.push({cur + days[cur] - 1, apples[cur]});
      }

      while (pq.size() && (cur > pq.top().first)) {
        pq.pop();
      }

      if (pq.size()) {
        auto [day, apple] = pq.top();
        pq.pop();

        ++ans;
        apple--;

        if (apple > 0) {
          pq.push({day, apple});
        }
      }

      ++cur;
    }

    return ans;
  }
};
// Runtime: 374 ms, faster than 27.43%
// Memory Usage: 47.1 MB, less than 99.78%
// 2022.8.18 at 奥盛大厦