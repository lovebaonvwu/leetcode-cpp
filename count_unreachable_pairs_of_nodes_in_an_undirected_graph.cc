class Solution {
  int Find(vector<int>& parent, int x) {
    if (parent[x] != x) {
      parent[x] = Find(parent, parent[x]);
    }

    return parent[x];
  }

  void Union(vector<int>& parent, int x, int y) {
    int px = Find(parent, x);
    int py = Find(parent, y);

    if (px != py) {
      parent[px] = py;
    }
  }

 public:
  long long countPairs(int n, vector<vector<int>>& edges) {
    vector<int> parent(n);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }

    for (auto& e : edges) {
      Union(parent, e[0], e[1]);
    }

    unordered_map<int, int> mp;
    for (auto p : parent) {
      ++mp[Find(parent, p)];
    }

    long long ans = 0;
    for (auto [p, cnt] : mp) {
      ans += 1LL * cnt * (n - cnt);
      n -= cnt;
    }

    return ans;
  }
};
// Runtime: 725 ms, faster than 79.36%
// Memory Usage: 146.9 MB, less than 92.29%
// 2022.8.29 at 奥盛大厦