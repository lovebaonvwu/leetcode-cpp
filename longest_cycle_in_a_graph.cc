class Solution {
 public:
  int longestCycle(vector<int>& edges) {
    vector<int> dist(edges.size());

    int ans = -1;
    for (int i = 0, d = 1; i < edges.size(); ++i) {
      int j = i, cur = d;
      while (j != -1 && !dist[j]) {
        dist[j] = d++;
        j = edges[j];
      }

      if (j != -1 && dist[j] >= cur) {
        ans = max(ans, d - dist[j]);
      }
    }

    return ans;
  }
};
// Runtime 175 ms
// Memory 90.1 MB
