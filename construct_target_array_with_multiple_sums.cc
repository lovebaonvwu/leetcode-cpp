class Solution {
 public:
  bool isPossible(vector<int>& target) {
    priority_queue<int> pq(target.begin(), target.end());

    long long sum = accumulate(target.begin(), target.end(), 0LL);

    while (true) {
      auto m = pq.top();
      pq.pop();

      sum -= m;

      if (m == 1) {
        return true;
      }

      if (sum == 1) {
        return true;
      }

      if (sum == 0 || sum >= m) {
        return false;
      }

      int r = m % sum;
      if (r == 0) {
        return false;
      }

      pq.push(r);

      sum += r;
    }

    return true;
  }
};
// Runtime: 44 ms, faster than 36.97%
// Memory Usage: 28.6 MB, less than 62.42%