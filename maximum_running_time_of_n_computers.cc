class Solution {
 public:
  long long maxRunTime(int n, vector<int>& batteries) {
    long long sum = accumulate(begin(batteries), end(batteries), 0LL);

    priority_queue<int> pq(begin(batteries), end(batteries));

    while (pq.top() > sum / n) {
      sum -= pq.top();
      pq.pop();
      --n;
    }

    return sum / n;
  }
};
// Runtime: 229 ms, faster than 59.26%
// Memory Usage: 58.2 MB, less than 10.82%
// 2022.1.20 at 奥盛大厦