class Solution {
 public:
  int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
    vector<vector<int>> mp(vals.size());

    for (auto& e : edges) {
      mp[e[0]].push_back(vals[e[1]]);
      mp[e[1]].push_back(vals[e[0]]);
    }

    int ans = INT_MIN;
    for (int i = 0; i < mp.size(); ++i) {
      sort(mp[i].rbegin(), mp[i].rend());

      int sum = vals[i];
      for (int j = 0, cnt = k; j < mp[i].size() && mp[i][j] > 0 && cnt > 0;
           ++j, --cnt) {
        sum += mp[i][j];
      }

      ans = max(ans, sum);
    }

    return ans;
  }
};
// Runtime 391 ms
// Memory 121.5 MB