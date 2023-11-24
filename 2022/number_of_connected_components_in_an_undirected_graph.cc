class Solution {
  vector<int> parent;

  int Find(int x) {
    if (parent[x] != x) {
      parent[x] = Find(parent[x]);
    }

    return parent[x];
  }

  void Union(int x, int y) {
    if (x != y) {
      parent[x] = y;
    }
  }

 public:
  int countComponents(int n, vector<vector<int>>& edges) {
    for (int i = 0; i < n; ++i) {
      parent.push_back(i);
    }

    int ans = n;
    for (auto& e : edges) {
      int px = Find(e[0]);
      int py = Find(e[1]);
      Union(px, py);
      if (px != py) {
        --ans;
      }
    }

    return ans;
  }
};
// Runtime 45 ms
// Memory 12.2 MB
// 2022.12.8 at 奥盛大厦