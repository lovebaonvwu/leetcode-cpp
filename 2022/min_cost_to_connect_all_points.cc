class Solution {
  int parents[1000];

  int find(int x) {
    if (parents[x] != x) {
      parents[x] = find(parents[x]);
    }

    return parents[x];
  }

  void _union(int x, int y) {
    x = find(x);
    y = find(y);

    if (x < y) {
      parents[y] = x;
    } else {
      parents[x] = y;
    }
  }

 public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    for (int i = 0; i < n; ++i) {
      parents[i] = i;
    }

    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>
        edges;

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int& a = points[i][0];
        int& b = points[i][1];
        int& c = points[j][0];
        int& d = points[j][1];

        int dis = abs(a - c) + abs(b - d);
        edges.push({dis, i, j});
      }
    }

    int cnt = 0;
    int ans = 0;

    while (!edges.empty() && cnt < n - 1) {
      auto [dis, x, y] = edges.top();
      edges.pop();

      if (find(x) != find(y)) {
        _union(x, y);
        ans += dis;
        ++cnt;
      }
    }

    return ans;
  }
};
// Runtime: 344 ms, faster than 68.87%
// Memory Usage: 57.9 MB, less than 70.73%
// 2022.4.26 at 茗筑美嘉

class Solution {
 public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<vector<array<int, 2>>> edges(n);

    vector<bool> visited(n);

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int& a = points[i][0];
        int& b = points[i][1];
        int& c = points[j][0];
        int& d = points[j][1];

        int dis = abs(a - c) + abs(b - d);
        edges[i].push_back({dis, j});
        edges[j].push_back({dis, i});
      }
    }

    visited[0] = true;

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>>
        pq(edges[0].begin(), edges[0].end());

    int cnt = 0;
    int ans = 0;

    while (!pq.empty() && cnt < n - 1) {
      auto [dis, next] = pq.top();
      pq.pop();

      if (visited[next]) {
        continue;
      }

      visited[next] = true;

      ans += dis;
      ++cnt;

      for (auto& e : edges[next]) {
        pq.push(e);
      }
    }

    return ans;
  }
};
// Runtime: 609 ms, faster than 51.94%
// Memory Usage: 163.2 MB, less than 18.31%
// 2022.4.26 at 茗筑美嘉