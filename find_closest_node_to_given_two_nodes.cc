class Solution {
 public:
  int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int n = edges.size();

    vector<int> dist1(n, -1);
    dfs(edges, dist1, node1, 0);
    vector<int> dist2(n, -1);
    dfs(edges, dist2, node2, 0);

    int ans = -1;
    int maxd = INT_MAX;
    for (int i = 0; i < n; ++i) {
      if (min(dist1[i], dist2[i]) >= 0 && max(dist1[i], dist2[i]) < maxd) {
        maxd = max(dist1[i], dist2[i]);
        ans = i;
      }
    }

    return ans;
  }

  void dfs(vector<int>& e, vector<int>& d, int node, int cur) {
    while (node != -1 && d[node] == -1) {
      d[node] = cur++;
      node = e[node];
    }
  }
};
// Runtime: 514 ms, faster than 27.97%
// Memory Usage: 97.5 MB, less than 74.05%
// 2022.8.25 at 奥盛大厦