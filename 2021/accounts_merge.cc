class Solution {
  vector<int> parent;

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }

    return parent[x];
  }

 public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    parent.resize(n);

    unordered_map<string, int> mp;

    for (int i = 0; i < n; ++i) {
      parent[i] = i;

      for (int j = 1; j < accounts[i].size(); ++j) {
        if (mp.find(accounts[i][j]) == mp.end()) {
          mp[accounts[i][j]] = i;
          continue;
        }

        int p = find(mp[accounts[i][j]]);
        parent[p] = i;
      }
    }

    unordered_map<int, set<string>> group;
    for (auto& m : mp) {
      int p = find(m.second);

      group[p].insert(m.first);
    }

    vector<vector<string>> ans;

    for (auto& g : group) {
      vector<string> t;
      t.push_back(accounts[g.first][0]);

      t.insert(t.begin() + 1, g.second.begin(), g.second.end());

      ans.push_back(t);
    }

    return ans;
  }
};
// Runtime: 76 ms, faster than 93.10%
// Memory Usage: 32.8 MB, less than 90.32%
// 2021.11.29 at 奥盛大厦