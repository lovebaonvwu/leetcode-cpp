class Solution {
  vector<int> parents;

  int Find(int a) {
    if (parents[a] != a) {
      parents[a] = Find(parents[a]);
    }

    return parents[a];
  }

  void Union(int a, int b) {
    if (a < b) {
      parents[a] = b;
    } else {
      parents[b] = a;
    }
  }

 public:
  int removeStones(vector<vector<int>>& stones) {
    int n = stones.size();

    parents.resize(n);

    for (int i = 0; i < n; ++i) {
      parents[i] = i;
    }

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
          int pa = Find(i);
          int pb = Find(j);

          if (pa != pb) {
            Union(pa, pb);
          }
        }
      }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      cnt += parents[i] == i;
    }

    return n - cnt;
  }
};
// Runtime: 320 ms, faster than 29.82%
// Memory Usage: 14.3 MB, less than 82.37%
// 2022.5.19 at 奥盛大厦