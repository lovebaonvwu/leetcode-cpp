class Solution {
 public:
  double maxProbability(int n,
                        vector<vector<int>>& edges,
                        vector<double>& succProb,
                        int start,
                        int end) {
    vector<vector<pair<int, double>>> g(n);
    for (int i = 0; i < edges.size(); ++i) {
      int a = edges[i][0], b = edges[i][1];
      g[a].push_back({b, succProb[i]});
      g[b].push_back({a, succProb[i]});
    }

    double maxProb[10001] = {0};
    maxProb[start] = 1.0;

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();

      for (auto& [next, nextProb] : g[cur]) {
        if (maxProb[cur] * nextProb > maxProb[next]) {
          maxProb[next] = maxProb[cur] * nextProb;
          q.push(next);
        }
      }
    }

    return maxProb[end];
  }
};
// Runtime 202 ms
// Memory 65.1 MB