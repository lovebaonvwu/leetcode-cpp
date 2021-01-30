class Solution {
 public:
  int minimumDeviation(vector<int>& nums) {
    int ans = INT_MAX;
    int cur_min = INT_MAX;

    priority_queue<int> pq;

    for (auto n : nums) {
      n = n % 2 ? n * 2 : n;

      pq.push(n);

      cur_min = min(cur_min, n);
    }

    while (pq.top() % 2 == 0) {
      ans = min(ans, pq.top() - cur_min);
      cur_min = min(cur_min, pq.top() / 2);

      pq.push(pq.top() / 2);
      pq.pop();
    }

    return min(ans, pq.top() - cur_min);
  }
};
// Runtime: 188 ms, faster than 98.67%
// Memory Usage: 71.4 MB, less than 90.08%