class Solution {
 public:
  vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
    unordered_map<int, vector<int>> g;
    for (auto& e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }

    int n = cost.size();
    vector<long long> ans(n);

    function<void(int, int, vector<long long>&)> dfs =
        [&](int root, int parent, vector<long long>& child_cost) -> void {
      vector<long long> tmp;
      for (auto& child : g[root]) {
        if (child == parent)
          continue;
        dfs(child, root, tmp);
      }

      tmp.push_back(cost[root]);
      sort(rbegin(tmp), rend(tmp));

      long long product = 0LL;
      int n = tmp.size();
      if (n < 3) {
        product = 1;
      } else {
        product = max(product, tmp[0] * tmp[1] * tmp[2]);
        product = max(product, tmp[0] * tmp[n - 1] * tmp[n - 2]);
      }

      ans[root] = product;
      child_cost.insert(child_cost.end(), tmp.begin(), tmp.end());
    };

    vector<long long> tmp;
    dfs(0, -1, tmp);

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
    unordered_map<int, vector<int>> g;
    for (auto& e : edges) {
      g[e[0]].push_back(e[1]);
      g[e[1]].push_back(e[0]);
    }

    int n = cost.size();
    vector<long long> ans(n);

    function<vector<long long>(int, int)> dfs =
        [&](int root, int parent) -> vector<long long> {
      vector<long long> tmp;
      for (auto& child : g[root]) {
        if (child == parent)
          continue;
        auto v = dfs(child, root);
        for (auto x : v)
          tmp.push_back(x);
      }

      tmp.push_back(cost[root]);
      sort(rbegin(tmp), rend(tmp));

      long long product = 0LL;
      int n = tmp.size();
      if (n < 3) {
        product = 1;
      } else {
        product = max(product, tmp[0] * tmp[1] * tmp[2]);
        product = max(product, tmp[0] * tmp[n - 1] * tmp[n - 2]);
      }

      ans[root] = product < 0 ? 0 : product;

      if (n <= 5)
        return tmp;

      return {tmp[0], tmp[1], tmp[2], tmp[n - 1], tmp[n - 2]};
    };

    dfs(0, -1);

    return ans;
  }
};
// 1741ms
// 305.28MB