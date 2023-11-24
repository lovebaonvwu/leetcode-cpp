class Solution {
 public:
  int findMaximizedCapital(int k,
                           int w,
                           vector<int>& profits,
                           vector<int>& capital) {
    int n = profits.size();
    vector<pair<int, int>> cp(n);
    for (int i = 0; i < n; ++i) {
      cp[i].first = capital[i];
      cp[i].second = profits[i];
    }

    sort(cp.begin(), cp.end());

    priority_queue<int> pq;

    for (int i = 0; k > 0; --k) {
      while (i < n && cp[i].first <= w) {
        pq.push(cp[i++].second);
      }

      if (pq.empty()) {
        break;
      }

      w += pq.top();
      pq.pop();
    }

    return w;
  }
};
// Runtime 246 ms
// Memory 78.1 MB
// 2023.2.23 at 奥盛大厦