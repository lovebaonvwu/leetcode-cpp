class Solution {
 public:
  int findTheWinner(int n, int k) {
    queue<int> q;

    for (int i = 1; i <= n; ++i) {
      q.push(i);
    }

    while (q.size() > 1) {
      int cnt = k;

      while (cnt-- > 1) {
        q.push(q.front());
        q.pop();
      }

      q.pop();
    }

    return q.front();
  }
};
// Runtime: 76 ms, faster than 13.54%
// Memory Usage: 24.5 MB, less than 16.31%
// 2021.11.23 at 奥盛大厦