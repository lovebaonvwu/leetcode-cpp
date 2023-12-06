class Solution {
 public:
  int maxNumberOfAlloys(int n,
                        int k,
                        int budget,
                        vector<vector<int>>& composition,
                        vector<int>& stock,
                        vector<int>& cost) {
    function<bool(long long)> helper = [&](long long target) -> bool {
      for (int i = 0; i < k; ++i) {
        long long sum = 0;
        for (int j = 0; j < n; ++j) {
          long long need = max(composition[i][j] * target - stock[j], 0LL);
          sum += cost[j] * need;
        }

        if (sum <= budget) {
          return true;
        }
      }

      return false;
    };

    int lo = 0, hi = 1e9 + 7;

    while (lo < hi) {
      int md = (lo + hi + 1) / 2;
      if (helper(md)) {
        lo = md;
      } else {
        hi = md - 1;
      }
    }

    return lo;
  }
};
// 82ms
// 55.13MB