class Solution {
 public:
  double maxPrice(vector<vector<int>>& items, int capacity) {
    priority_queue<pair<double, int>> pq;
    for (int i = 0; i < items.size(); ++i) {
      auto& e = items[i];
      pq.push({e[0] * 1.0 / e[1], i});
    }

    double ans = 0.0;
    while (!pq.empty() && capacity > 0) {
      auto cur = pq.top();
      auto& e = items[cur.second];
      pq.pop();

      int add = min(e[1], capacity);
      ans += add * 1.0 / e[1] * e[0];

      capacity -= add;
    }

    return capacity > 0 ? -1 : ans;
  }
};
// Runtime 730 ms
// Memory 170.5 MB
// 2023.2.5 at 茗筑美嘉