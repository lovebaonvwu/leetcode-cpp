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

  bool Union(int x, int y) {
    int px = Find(x);
    int py = Find(y);

    if (px == py) {
      return false;
    }

    if (rank[px] > rank[py]) {
      parent[py] = px;
      ++rank[px];
    } else {
      parent[px] = py;
      ++rank[py];
    }

    return true;
  }

  int GroupCount() {
    int cnt = 0;
    for (int i = 0; i < size; ++i) {
      if (i == Find(i)) {
        ++cnt;
      }
    }

    cout << cnt << endl;
    return cnt;
  }

 private:
  vector<int> parent;
  vector<int> rank;
  int size;
};

class Solution {
 public:
  int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    sort(edges.rbegin(), edges.rend());

    UnionFind alice(n), bob(n);

    int added = 0;
    for (auto& e : edges) {
      int type = e[0], u = e[1] - 1, v = e[2] - 1;
      if (type == 3) {
        added += (alice.Union(u, v) | bob.Union(u, v));
      } else if (type == 2) {
        added += bob.Union(u, v);
      } else if (type == 1) {
        added += alice.Union(u, v);
      }
    }

    return (alice.GroupCount() == 1 && bob.GroupCount() == 1)
               ? (edges.size() - added)
               : -1;
  }
};
// Runtime 952 ms
// Memory 138.9 MB