class DisjointSet {
 public:
  DisjointSet(int n) : size(n) {
    parent.resize(size);
    iota(begin(parent), end(parent), 0);

    rank.resize(size);
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

    if (rank[px] > rank[py]) {
      parent[py] = px;
    } else {
      parent[px] = py;
    }
  }

  int UniqueSet() {
    int ret = 0;
    for (int i = 0; i < size; ++i) {
      ret += parent[i] == i;
    }

    return ret;
  }

 private:
  vector<int> parent;
  vector<int> rank;
  int size;
};

/**
 * Definition for a category handler.
 * class CategoryHandler {
 * public:
 *     CategoryHandler(vector<int> categories);
 *     bool haveSameCategory(int a, int b);
 * };
 */
class Solution {
 public:
  int numberOfCategories(int n, CategoryHandler* categoryHandler) {
    DisjointSet ds(n);

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (categoryHandler->haveSameCategory(i, j)) {
          ds.Union(i, j);
        }
      }
    }

    return ds.UniqueSet();
  }
};
// 112 ms
// 105.00 MB