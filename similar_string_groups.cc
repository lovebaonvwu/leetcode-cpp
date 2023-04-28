class UnionFind {
 public:
  UnionFind(int n) : size(n), rank(0) {
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

    if (rank[px] > rank[py]) {
      parent[py] = px;
      ++rank[px];
    } else if (rank[py] >= rank[px]) {
      parent[px] = py;
      ++rank[py];
    }
  }

  int GroupCount() {
    int count = 0;

    for (int i = 0; i < size; ++i) {
      if (Find(i) == i) {
        ++count;
      }
    }

    return count;
  }

 private:
  vector<int> parent;
  vector<int> rank;
  int size;
};

class Solution {
 public:
  int numSimilarGroups(vector<string>& strs) {
    int n = strs.size();

    UnionFind ds(n);

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (isSimilar(strs[i], strs[j])) {
          ds.Union(i, j);
        }
      }
    }

    return ds.GroupCount();
  }

 private:
  bool isSimilar(const string& a, const string& b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i) {
      cnt += a[i] != b[i];
    }

    return cnt == 2 || cnt == 0;
  }
};
// Runtime 164 ms
// Memory 10.1 MB