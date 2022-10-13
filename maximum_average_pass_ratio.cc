class Solution {
  double gain(double pass, double total) {
    return (pass + 1) / (total + 1) - pass / total;
  }

 public:
  double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    double total = 0;
    priority_queue<pair<double, pair<int, int>>,
                   vector<pair<double, pair<int, int>>>>
        pq;

    for (auto& c : classes) {
      total += (double)c[0] / c[1];
      pq.push({gain(c[0], c[1]), {c[0], c[1]}});
    }

    while (extraStudents-- > 0) {
      auto [g, c] = pq.top();
      pq.pop();

      auto p = c.first;
      auto t = c.second;

      total += g;
      pq.push({gain(p + 1, t + 1), {p + 1, t + 1}});
    }

    return total / pq.size();
  }
};
// Runtime: 1894 ms, faster than 19.04%
// Memory Usage: 93.4 MB, less than 65.40%
// 2022.10.13 at 奥盛大厦