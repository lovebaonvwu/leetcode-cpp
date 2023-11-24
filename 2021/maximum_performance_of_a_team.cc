class Solution {
 public:
  int maxPerformance(int n,
                     vector<int>& speed,
                     vector<int>& efficiency,
                     int k) {
    vector<pair<int, int>> es;

    for (int i = 0; i < speed.size(); ++i) {
      es.push_back({efficiency[i], speed[i]});
    }

    sort(es.rbegin(), es.rend());

    priority_queue<int, vector<int>, greater<int>> pq;

    long long sum = 0, ans = 0;

    for (auto& [e, s] : es) {
      sum += s;
      pq.push(s);

      if (pq.size() > k) {
        sum -= pq.top();
        pq.pop();
      }

      ans = max(ans, sum * e);
    }

    return ans % 1000000007;
  }
};
// Runtime: 104 ms, faster than 30.61%
// Memory Usage: 36.9 MB, less than 31.78%