class Solution {
 public:
  long long maxSpending(vector<vector<int>>& values) {
    priority_queue<int, vector<int>, greater<int>> pq;
    long long ans = 0;

    int m = values.size();
    int n = values[0].size();
    int cnt = 1;
    for (int j = n - 1; j >= 0; --j, ++cnt) {
      for (int i = 0; i < m; ++i) {
        pq.push(values[i][j]);
      }

      ans += (1LL * pq.top() * cnt);
      pq.pop();
    }

    while (!pq.empty()) {
      ans += (1LL * pq.top() * cnt);
      pq.pop();
      ++cnt;
    }

    return ans;
  }
};
// 214ms
// 59.46MB