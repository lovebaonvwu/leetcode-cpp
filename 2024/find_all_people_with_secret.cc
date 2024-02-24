class Solution {
 public:
  vector<int> findAllPeople(int n,
                            vector<vector<int>>& meetings,
                            int firstPerson) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.emplace(0, 0);
    pq.emplace(0, firstPerson);

    unordered_map<int, vector<pair<int, int>>> mp;
    for (auto& m : meetings) {
      int x = m[0];
      int y = m[1];
      int t = m[2];

      mp[x].emplace_back(y, t);
      mp[y].emplace_back(x, t);
    }

    vector<int> visited(n);
    while (!pq.empty()) {
      auto [t0, x] = pq.top();
      pq.pop();

      if (visited[x]) {
        continue;
      }

      visited[x] = true;
      for (auto& [y, t1] : mp[x]) {
        if (t1 >= t0) {
          pq.push({t1, y});
        }
      }
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (visited[i]) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// 499 ms
// 187.62MB