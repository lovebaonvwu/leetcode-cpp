class Solution {
 public:
  int connectSticks(vector<int>& sticks) {
    priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(),
                                                      sticks.end());

    int ans = 0;
    while (!pq.empty()) {
      int a = pq.top();
      pq.pop();

      ans += a;
      if (pq.empty()) {
        ans -= a;
        break;
      }

      int b = pq.top();
      pq.pop();
      ans += b;

      pq.push(a + b);
    }

    return ans;
  }
};
// Runtime 88 ms
// Memory 22.7 MB
// 2023.1.30 at 奥盛大厦