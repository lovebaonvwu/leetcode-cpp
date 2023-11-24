class Solution {
  void dfs(unordered_map<int, vector<int>>& mp,
           unordered_set<int>& st,
           int node) {
    for (auto ancestor : mp[node]) {
      st.insert(ancestor);

      dfs(mp, st, ancestor);
    }
  }

 public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> mp;

    for (auto& e : edges) {
      mp[e[1]].push_back(e[0]);
    }

    vector<vector<int>> ans(n);

    for (int i = 0; i < n; ++i) {
      unordered_set<int> st;
      dfs(mp, st, i);

      ans[i] = vector<int>(st.begin(), st.end());
      sort(ans[i].begin(), ans[i].end());
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
  void dfs(unordered_map<int, vector<int>>& mp,
           vector<int>& ancestors,
           unordered_map<int, bool>& visited,
           int node) {
    for (auto ancestor : mp[node]) {
      if (visited[ancestor]) {
        continue;
      }

      ancestors.push_back(ancestor);

      visited[ancestor] = true;

      dfs(mp, ancestors, visited, ancestor);
    }
  }

 public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    unordered_map<int, vector<int>> mp;

    for (auto& e : edges) {
      mp[e[1]].push_back(e[0]);
    }

    vector<vector<int>> ans(n);

    for (int i = 0; i < n; ++i) {
      unordered_map<int, bool> visited;
      dfs(mp, ans[i], visited, i);

      sort(ans[i].begin(), ans[i].end());
    }

    return ans;
  }
};
// Runtime: 898 ms, faster than 19.40%
// Memory Usage: 147 MB, less than 35.84%
// 2022.3.10 at 奥盛大厦

class Solution {
 public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int>> ans(n), g(n);

    function<void(int, int)> dfs = [&](int i, int anc) {
      for (auto next : g[i]) {
        if (ans[next].empty() || ans[next].back() != anc) {
          ans[next].push_back(anc);

          dfs(next, anc);
        }
      }
    };

    for (auto& e : edges) {
      g[e[0]].push_back(e[1]);
    }

    for (int i = 0; i < n; ++i) {
      dfs(i, i);
    }

    return ans;
  }
};
// Runtime: 164 ms, faster than 92.99%
// Memory Usage: 59.9 MB, less than 94.40%
// 2022.3.10 at 奥盛大厦