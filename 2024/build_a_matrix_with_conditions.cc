class Solution {
  vector<int> topoSort(int k, const vector<vector<int>>& conditions) {
    vector<vector<int>> g(k + 1, vector<int>());
    vector<int> indegree(k + 1);
    for (auto condition : conditions) {
      g[condition[0]].push_back(condition[1]);
      ++indegree[condition[1]];
    }

    vector<int> visited(k + 1);
    queue<int> q;
    for (int i = 1; i <= k; ++i) {
      if (indegree[i] == 0) {
        q.push(i);
        visited[i] = true;
      }
    }

    vector<int> ret;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      ret.push_back(cur);

      for (auto next : g[cur]) {
        --indegree[next];
        if (indegree[next] == 0) {
          q.push(next);
        }
      }
    }

    return ret.size() == k ? ret : vector<int>();
  }

 public:
  vector<vector<int>> buildMatrix(int k,
                                  vector<vector<int>>& rowConditions,
                                  vector<vector<int>>& colConditions) {
    vector<int> rowOrder = topoSort(k, rowConditions);
    vector<int> colOrder = topoSort(k, colConditions);

    if (rowOrder.size() == 0 || colOrder.size() == 0) {
      return {};
    }

    vector<vector<int>> ans(k, vector<int>(k));
    for (int i = 0; i < rowOrder.size(); ++i) {
      for (int j = 0; j < colOrder.size(); ++j) {
        if (colOrder[j] == rowOrder[i]) {
          ans[i][j] = rowOrder[i];
        }
      }
    }

    return ans;
  }
};
// 112 ms
// 65.34 MB
