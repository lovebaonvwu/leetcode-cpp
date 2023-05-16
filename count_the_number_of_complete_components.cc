class DSU {
 public:
  DSU(int size) : size_(size), groupCount(size) {
    parent.resize(size_);
    rank.resize(size_);
    childrenCount.resize(size_, 1);

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

    --groupCount;
    childrenCount[px] = childrenCount[py] =
        childrenCount[px] + childrenCount[py];

    if (rank[px] >= rank[py]) {
      parent[py] = px;
      ++rank[px];
    } else {
      parent[px] = py;
      ++rank[py];
    }
  }

  int GetGroupCount() { return groupCount; }

  int GetChildrenCount(int x) { return childrenCount[Find(x)]; }

 private:
  vector<int> parent;
  vector<int> rank;
  vector<int> childrenCount;

  int size_;
  int groupCount;
};

class Solution {
 public:
  int countCompleteComponents(int n, vector<vector<int>>& edges) {
    DSU ds(n);
    vector<int> edgesCount(n, 0);

    for (auto& e : edges) {
      ds.Union(e[0], e[1]);
      ++edgesCount[e[0]];
      ++edgesCount[e[1]];
    }

    unordered_set<int> group;
    for (int i = 0; i < n; ++i) {
      group.insert(ds.Find(i));
    }

    for (int i = 0; i < n; ++i) {
      if (ds.GetChildrenCount(i) != edgesCount[i] + 1) {
        group.erase(ds.Find(i));
      }
    }

    return group.size();
  }
};
// Runtime 241 ms
// Memory 112.3 MB