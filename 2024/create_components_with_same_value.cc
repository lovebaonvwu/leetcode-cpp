class Solution {
 public:
  int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> g;
    for (auto& e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }

    function<int(int, int, int)> dfs = [&](int node, int parent,
                                           int divisor) -> int {
      int sum = nums[node];
      for (auto neighbor : g[node]) {
        if (neighbor == parent)
          continue;
        sum += dfs(neighbor, node, divisor);
      }
      return sum == divisor ? 0 : sum;
    };

    int total = accumulate(begin(nums), end(nums), 0);
    for (int i = 1; i <= total; ++i) {
      if (total % i == 0) {
        if (dfs(0, -1, i) == 0) {
          return total / i - 1;
        }
      }
    }

    return 0;
  }
};
// 998 ms
// 148.00 MB
