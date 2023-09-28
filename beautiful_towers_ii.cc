class Solution {
 public:
  long long maximumSumOfHeights(vector<int>& maxHeights) {
    stack<int> stk;
    int n = maxHeights.size();
    long long cur = 0;
    stk.push(-1);
    vector<long long> left(n);
    for (int i = 0; i < n; ++i) {
      while (stk.size() > 1 && maxHeights[i] < maxHeights[stk.top()]) {
        int idx = stk.top();
        stk.pop();

        cur -= 1LL * (idx - stk.top()) * maxHeights[idx];
      }

      cur += 1LL * maxHeights[i] * (i - stk.top());
      stk.push(i);
      left[i] = cur;
    }

    while (stk.size() > 0) {
      stk.pop();
    }

    stk.push(n);

    long long ans = 0;
    cur = 0;
    for (int i = n - 1; i >= 0; --i) {
      while (stk.size() > 1 && maxHeights[i] < maxHeights[stk.top()]) {
        int idx = stk.top();
        stk.pop();

        cur -= 1LL * (stk.top() - idx) * maxHeights[idx];
      }

      cur += 1LL * maxHeights[i] * (stk.top() - i);
      stk.push(i);

      ans = max(ans, cur + left[i] - maxHeights[i]);
    }

    return ans;
  }
};
// 187ms
// 89.85MB