class Solution {
  vector<int> parent;

 public:
  bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
    parent.resize(n);

    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }

    for (auto& e : edges) {
      join(find(e[0]), find(e[1]));
    }

    return find(start) == find(end);
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }

    return parent[x];
  }

  void join(int x, int y) { parent[x] = y; }
};
// Runtime: 340 ms, faster than 98.38%
// Memory Usage: 111 MB, less than 98.01%
// 2021.11.4 at 奥盛大厦