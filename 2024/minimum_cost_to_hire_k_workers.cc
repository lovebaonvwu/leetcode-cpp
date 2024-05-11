class Solution {
 public:
  double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
    vector<pair<int, int>> workers;
    int n = quality.size();
    for (int i = 0; i < n; ++i) {
      workers.push_back({quality[i], wage[i]});
    }

    sort(begin(workers), end(workers), [&](auto& a, auto& b) {
      return a.second * 1.0 / a.first < b.second * 1.0 / b.first;
    });

    priority_queue<int> pq;
    double ans = 1e20;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      double unit = workers[i].second * 1.0 / workers[i].first;

      sum += workers[i].first;

      while (pq.size() > k - 1) {
        sum -= pq.top();
        pq.pop();
      }

      pq.push(workers[i].first);
      if (pq.size() == k) {
        ans = min(ans, unit * sum);
      }
    }

    return ans;
  }
};
// 35 ms
// 24.98 MB