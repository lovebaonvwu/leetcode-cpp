class Solution {
 public:
  double averageWaitingTime(vector<vector<int>>& customers) {
    double cur = 0.0, wait = 0.0;

    for (auto& c : customers) {
      cur = max(cur, (double)c[0]) + c[1];
      wait += cur - c[0];
    }

    return (double)wait / customers.size();
  }
};
// Runtime: 196 ms, faster than 99.74%
// Memory Usage: 72.8 MB, less than 99.59%

class Solution {
 public:
  double averageWaitingTime(vector<vector<int>>& customers) {
    double cur = 0.0, wait = 0.0;

    for (auto& c : customers) {
      cur = max(cur, 1.0 * c[0]) + c[1];
      wait += cur - c[0];
    }

    return 1.0 * wait / customers.size();
  }
};
// Runtime: 192 ms, faster than 99.85%
// Memory Usage: 72.9 MB, less than 99.33%