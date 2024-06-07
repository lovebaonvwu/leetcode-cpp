class Solution {
 public:
  vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
    int n = aliceArrows.size();
    int maxScore = 0;
    vector<int> ans;
    function<void(int, int, int, vector<int>)> dfs =
        [&](int A, int i, int total, vector<int> bob) -> void {
      if (i == n) {
        if (A < 0)
          return;
        if (total > maxScore) {
          maxScore = total;
          ans = bob;
        }
        return;
      }

      dfs(A, i + 1, total, bob);

      if (A > aliceArrows[i]) {
        bob[i] = aliceArrows[i] + 1;
        dfs(A - bob[i], i + 1, i + total, bob);
      }
    };

    vector<int> bob(12);
    dfs(numArrows, 0, 0, bob);

    ans[0] += numArrows - accumulate(begin(ans), end(ans), 0);

    return ans;
  }
};
// 430 ms
// 109.88 MB