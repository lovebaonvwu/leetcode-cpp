class DSU {
 public:
  DSU(int n) {
    parent.resize(n);
    rank.resize(n);

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

    if (rank[px] <= rank[py]) {
      parent[px] = py;
      ++rank[py];
    } else {
      parent[py] = px;
      ++rank[px];
    }
  }

  int Count() {
    int cnt = 0;
    for (int i = 0; i < parent.size(); ++i) {
      Find(i);
      if (parent[i] == i) {
        ++cnt;
      }
    }

    return cnt;
  }

  void Print() {
    for (int i = 0; i < parent.size(); ++i) {
      cout << parent[i] << " ";
    }

    cout << endl;
  }

 private:
  vector<int> parent;
  vector<int> rank;
};

class Solution {
 public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) {
      return -1;
    }

    DSU dsu(n);

    for (auto& conn : connections) {
      dsu.Union(conn[0], conn[1]);
    }

    return dsu.Count() - 1;
  }
};
// Runtime 91 ms
// Memory 37.7 MB