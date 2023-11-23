class Solution {
 public:
  vector<int> leftmostBuildingQueries(vector<int>& heights,
                                      vector<vector<int>>& queries) {
    int n = queries.size();
    vector<int> ans(n, -1);
    unordered_map<int, vector<pair<int, int>>> mp;

    for (int i = 0; i < n; ++i) {
      int a = queries[i][0];
      int b = queries[i][1];

      if (a < b && heights[a] < heights[b]) {
        ans[i] = b;
      } else if (b < a && heights[b] < heights[a]) {
        ans[i] = a;
      } else if (a == b) {
        ans[i] = a;
      } else if (a < b && heights[a] >= heights[b]) {
        mp[b].push_back({heights[a], i});
      } else if (b < a && heights[b] >= heights[a]) {
        mp[a].push_back({heights[b], i});
      }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;

    for (int i = 0; i < heights.size(); ++i) {
      while (!pq.empty() && pq.top().first < heights[i]) {
        ans[pq.top().second] = i;
        pq.pop();
      }

      for (auto& p : mp[i]) {
        pq.push(p);
      }
    }

    return ans;
  }
};
// 435ms
// 211.98MB