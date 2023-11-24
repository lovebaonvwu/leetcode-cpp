class Solution {
 public:
  int minReorder(int n, vector<vector<int>>& connections) {
    queue<int> q;

    q.push(0);

    int ans = 0;

    while (!q.empty()) {
      int city = q.front();
      q.pop();

      for (int i = 0; i < n - 1; ++i) {
        if (connections[i][0] == city) {
          ++ans;
          q.push(connections[i][1]);
          connections[i][0] = -1;
          connections[i][1] = -1;
        } else if (connections[i][1] == city) {
          q.push(connections[i][0]);
          connections[i][0] = -1;
          connections[i][1] = -1;
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<int>> edges(n);

    for (auto& c : connections) {
      edges[c[0]].push_back(c[1]);
      edges[c[1]].push_back(-c[0]);
    }

    return dfs(edges, vector<int>(n) = {}, 0);
  }

  int dfs(vector<vector<int>>& edges, vector<int>& visited, int from) {
    int change = 0;
    visited[from] = true;

    for (auto city : edges[from]) {
      if (!visited[abs(city)]) {
        change += dfs(edges, visited, abs(city)) + (city > 0);
      }
    }

    return change;
  }
};
// Runtime: 484 ms, faster than 92.04%
// Memory Usage: 78.6 MB, less than 100.00%