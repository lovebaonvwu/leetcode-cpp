class UnionFind {
 public:
  UnionFind(int n) : size(n) {
    parent.resize(size);
    rank.resize(size);

    iota(parent.begin(), parent.end(), 0);
  }

  int Find(int x) {
    if (parent[x] != x) {
      parent[x] = Find(parent[x]);
    }

    return parent[x];
  }

  void Union(int x, int y) {
    int px = Find(x);
    int py = Find(y);

    if (px == py) {
      return;
    }

    if (px > py) {
      parent[py] = px;
      ++rank[px];
    } else {
      parent[px] = py;
      ++rank[py];
    }
  }

 private:
  vector<int> parent;
  vector<int> rank;
  int size;
};

class Solution {
 public:
  vector<bool> distanceLimitedPathsExist(int n,
                                         vector<vector<int>>& edgeList,
                                         vector<vector<int>>& queries) {
    for (int i = 0; i < queries.size(); ++i) {
      queries[i].push_back(i);
    }

    sort(edgeList.begin(), edgeList.end(),
         [&](auto& a, auto& b) { return a[2] < b[2]; });

    sort(queries.begin(), queries.end(),
         [&](auto& a, auto& b) { return a[2] < b[2]; });

    UnionFind ds(n);

    vector<bool> ans(queries.size());
    int k = 0;
    for (auto& q : queries) {
      int u = q[0], v = q[1], limit = q[2], i = q[3];
      for (; k < edgeList.size() && edgeList[k][2] < limit; ++k) {
        ds.Union(edgeList[k][0], edgeList[k][1]);
      }

      ans[i] = ds.Find(u) == ds.Find(v);
    }

    return ans;
  }
};
// Runtime 638 ms
// Memory 110.1 MB