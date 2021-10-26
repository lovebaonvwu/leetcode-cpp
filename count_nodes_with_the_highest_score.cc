class Solution {
  int ans = 0;
  long curMax = 0;

 public:
  int countHighestScoreNodes(vector<int>& parents) {
    int n = parents.size();

    vector<vector<int>> g(n);

    for (int i = 1; i < n; ++i) {
      g[parents[i]].push_back(i);
    }

    dfs(g, 0, n);

    return ans;
  }

  long dfs(vector<vector<int>>& g, int root, int n) {
    long left = 0, right = 0;

    if (g[root].size() > 0) {
      left = dfs(g, g[root][0], n);
    }

    if (g[root].size() > 1) {
      right = dfs(g, g[root][1], n);
    }

    long parent = root == 0 ? 1 : (n - 1 - left - right);
    long sum = parent * (left == 0 ? 1 : left) * (right == 0 ? 1 : right);

    if (sum > curMax) {
      curMax = sum;
      ans = 1;
    } else if (sum == curMax) {
      ++ans;
    }

    return left + right + 1;
  }
};
// Runtime: 547 ms, faster than 39.74%
// Memory Usage: 109.7 MB, less than 87.36%
// 2021.10.26 at 奥盛大厦