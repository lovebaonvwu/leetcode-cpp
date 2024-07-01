class DisjointSet {
 public:
  DisjointSet(int n) : size(n) {
    parents.resize(size);
    ranks.resize(size);

    iota(begin(parents), end(parents), 0);
  }

  int Find(int x) {
    if (parents[x] != x) {
      parents[x] = Find(parents[x]);
    }

    return parents[x];
  }

  void Union(int x, int y) {
    int px = Find(x);
    int py = Find(y);

    if (px == py)
      return;

    if (ranks[px] > ranks[py]) {
      parents[py] = px;
    } else if (ranks[py] > ranks[px]) {
      parents[px] = py;
    } else {
      parents[py] = px;
      ++ranks[px];
    }
  }

  bool IsWhole() {
    for (int i = 1; i < size; ++i) {
      if (Find(parents[i]) != Find(parents[0]))
        return false;
    }

    return true;
  }

 private:
  int size;
  vector<int> parents;
  vector<int> ranks;
};

class Solution {
 public:
  int earliestAcq(vector<vector<int>>& logs, int n) {
    sort(begin(logs), end(logs));

    DisjointSet ds(n);

    for (auto& log : logs) {
      int t = log[0];
      int x = log[1];
      int y = log[2];

      ds.Union(x, y);

      if (ds.IsWhole())
        return t;
    }

    return -1;
  }
};
// 19 ms
// 16.56 MB