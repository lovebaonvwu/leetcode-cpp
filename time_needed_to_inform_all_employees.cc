class Solution {
 public:
  int numOfMinutes(int n,
                   int headID,
                   vector<int>& manager,
                   vector<int>& informTime) {
    unordered_map<int, vector<pair<int, int>>> mp;

    for (int i = 0; i < n; ++i) {
      if (i != headID) {
        mp[manager[i]].push_back({i, informTime[i]});
      }
    }

    queue<pair<int, int>> q;
    q.push({headID, informTime[headID]});

    int ans = 0;
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();

      ans = max(ans, cur.second);

      for (auto& next : mp[cur.first]) {
        q.push({next.first, cur.second + next.second});
      }
    }

    return ans;
  }
};
// Runtime 534 ms
// Memory 163.1 MB