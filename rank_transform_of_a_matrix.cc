class Solution {
  vector<int> parent;

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }

    return parent[x];
  }

  void uni(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) {
      return;
    }

    if (x < y) {
      parent[y] = x;
    } else {
      parent[x] = y;
    }
  }

 public:
  vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    parent.resize(m * n);

    for (int i = 0; i < m * n; ++i) {
      parent[i] = i;
    }

    for (int i = 0; i < m; ++i) {
      vector<pair<int, int>> tmp;

      for (int j = 0; j < n; ++j) {
        tmp.push_back({matrix[i][j], i * n + j});
      }

      sort(tmp.begin(), tmp.end());

      for (int j = 1; j < n; ++j) {
        if (tmp[j].first == tmp[j - 1].first) {
          uni(tmp[j].second, tmp[j - 1].second);
        }
      }
    }

    for (int j = 0; j < n; ++j) {
      vector<pair<int, int>> tmp;

      for (int i = 0; i < m; ++i) {
        tmp.push_back({matrix[i][j], i * n + j});
      }

      sort(tmp.begin(), tmp.end());

      for (int i = 1; i < m; ++i) {
        if (tmp[i].first == tmp[i - 1].first) {
          uni(tmp[i].second, tmp[i - 1].second);
        }
      }
    }

    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        mp[find(i * n + j)].push_back(i * n + j);
      }
    }

    vector<vector<int>> ans(m, vector<int>(n, 0));

    vector<pair<int, int>> nums;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        nums.push_back({matrix[i][j], i * n + j});
      }
    }

    vector<int> rowRank(m, 0);
    vector<int> colRank(n, 0);

    sort(nums.begin(), nums.end());

    for (auto p : nums) {
      int x = p.second / n;
      int y = p.second % n;

      if (ans[x][y] > 0) {
        continue;
      }

      int rank = 0;
      for (auto member : mp[find(x * n + y)]) {
        rank = max(rank, rowRank[member / n]);
        rank = max(rank, colRank[member % n]);
      }

      for (auto member : mp[find(x * n + y)]) {
        ans[member / n][member % n] = rank + 1;
        rowRank[member / n] = rank + 1;
        colRank[member % n] = rank + 1;
      }
    }

    return ans;
  }
};
// Runtime: 404 ms, faster than 39.55%
// Memory Usage: 87.6 MB, less than 64.92%
// 2021.8.8 at 奥盛大厦