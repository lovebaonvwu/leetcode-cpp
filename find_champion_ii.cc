class Solution {
 public:
  int findChampion(int n, vector<vector<int>>& edges) {
    vector<int> in_degree(n);
    for (auto& e : edges) {
      ++in_degree[e[1]];
    }

    int ans = -1;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (in_degree[i] > 0)
        ++cnt;
      else
        ans = i;
    }

    return (n - cnt > 1) ? -1 : ans;
  }
};
// 181ms
// 89.00MB