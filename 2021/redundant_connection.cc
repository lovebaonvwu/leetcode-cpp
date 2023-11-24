class Solution {
  unordered_map<int, int> parent;

 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    for (auto& e : edges) {
      auto a = e[0];
      auto b = e[1];

      if (parent.find(a) == parent.end()) {
        parent[a] = a;
      }

      if (parent.find(b) == parent.end()) {
        parent[b] = b;
      }

      auto pa = Find(a);
      auto pb = Find(b);

      if (pa == pb) {
        return e;
      }

      Union(a, b);
    }

    return {};
  }

  int Find(int x) {
    if (parent[x] != x) {
      parent[x] = Find(parent[x]);
    }

    return parent[x];
  }

  void Union(int a, int b) {
    auto pa = parent[a];
    auto pb = parent[b];

    if (pa < pb) {
      parent[pb] = pa;
    } else {
      parent[pa] = pb;
    }
  }
};
// Runtime: 12 ms, faster than 31.89%
// Memory Usage: 9.2 MB, less than 29.38%