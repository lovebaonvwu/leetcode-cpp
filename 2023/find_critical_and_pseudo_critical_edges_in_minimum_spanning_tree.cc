class DisjointSet {
 public:
  DisjointSet(int n) : size(n) {
    parents.resize(size);
    iota(parents.begin(), parents.end(), 0);
    rank.resize(size);
  }

  int Find(int x) {
    if (parents[x] != x) {
      parents[x] = Find(parents[x]);
    }

    return parents[x];
  }

  bool Union(int x, int y) {
    int px = Find(x);
    int py = Find(y);

    if (px == py) {
      return false;
    }

    if (rank[py] > rank[px]) {
      parents[px] = py;
    } else if (rank[px] > rank[py]) {
      parents[py] = px;
    } else {
      parents[px] = py;
      ++rank[py];
    }

    return true;
  }

 private:
  vector<int> parents;
  vector<int> rank;
  int size;
};

class Solution {
 public:
  vector<vector<int>> findCriticalAndPseudoCriticalEdges(
      int n,
      vector<vector<int>>& edges) {
    for (int i = 0; i < edges.size(); ++i) {
      edges[i].push_back(i);
    }

    sort(edges.begin(), edges.end(), [&](const auto& e1, const auto& e2) {
      if (e1[2] != e2[2]) {
        return e1[2] < e2[2];
      }
      return e1 < e2;
    });

    auto MST = [&](int ex = -1, int in = -1) -> int {
      auto ds = DisjointSet(n);
      int count = 0;
      int cost = 0;
      if (in >= 0) {
        ds.Union(edges[in][0], edges[in][1]);
        ++count;
        cost += edges[in][2];
      }

      for (int i = 0; i < edges.size(); ++i) {
        if (i == ex) {
          continue;
        }

        if (ds.Union(edges[i][0], edges[i][1])) {
          ++count;
          cost += edges[i][2];
        }
      }

      return count == n - 1 ? cost : INT_MAX;
    };

    int min_cost = MST();
    vector<vector<int>> ans(2);
    for (int i = 0; i < edges.size(); ++i) {
      if (MST(i) > min_cost) {
        ans[0].push_back(edges[i][3]);
      } else if (MST(-1, i) == min_cost) {
        ans[1].push_back(edges[i][3]);
      }
    }

    return ans;
  }
};
// 105ms
// 19.20MB