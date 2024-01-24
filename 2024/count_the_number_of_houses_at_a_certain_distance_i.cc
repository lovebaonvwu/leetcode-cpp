class Solution {
 public:
  vector<int> countOfPairs(int n, int x, int y) {
    if (x > y)
      swap(x, y);

    vector<int> ans(n);

    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        int dist = min(j - i, abs(x - i) + 1 + abs(j - y));

        ans[dist - 1] += 2;
      }
    }

    return ans;
  }
};
// 10ms
// 9.28MB