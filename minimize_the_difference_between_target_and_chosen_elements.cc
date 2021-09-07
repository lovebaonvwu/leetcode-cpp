class Solution {
 public:
  int minimizeTheDifference(vector<vector<int>>& mat, int target) {
    bitset<5000> st(1);

    for (auto& r : mat) {
      bitset<5000> tmp;

      for (auto i : r) {
        tmp = tmp | (st << i);
      }

      swap(st, tmp);
    }

    int ans = INT_MAX;

    for (int i = 0; i <= 5000; ++i) {
      if (st[i]) {
        ans = min(ans, abs(i - target));
      }
    }

    return ans;
  }
};
// Runtime: 92 ms, faster than 88.57%
// Memory Usage: 13 MB, less than 87.25%
// 2021.9.7 at 奥盛大厦

class Solution {
  int memo[70][5000];
  int m;
  int n;
  int t;

 public:
  int minimizeTheDifference(vector<vector<int>>& mat, int target) {
    memset(memo, -1, sizeof(memo));
    m = mat.size();
    n = mat[0].size();
    t = target;

    return dfs(mat, 0, 0);
  }

  int dfs(vector<vector<int>>& mat, int r, int sum) {
    if (r >= m) {
      return abs(sum - t);
    }

    if (memo[r][sum] > -1) {
      return memo[r][sum];
    }

    int res = INT_MAX;
    for (int i = 0; i < n; ++i) {
      res = min(res, dfs(mat, r + 1, mat[r][i] + sum));
    }

    return memo[r][sum] = res;
  }
};
// Runtime: 1268 ms, faster than 46.63%
// Memory Usage: 14.6 MB, less than 57.34%
// 2021.9.7 at 奥盛大厦