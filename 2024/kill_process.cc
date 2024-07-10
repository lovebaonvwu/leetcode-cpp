class Solution {
 public:
  vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    unordered_map<int, vector<int>> g;
    int n = pid.size();
    for (int i = 0; i < n; ++i) {
      g[ppid[i]].push_back(pid[i]);
    }

    vector<int> ans;
    queue<int> q;
    q.push(kill);

    while (!q.empty()) {
      auto parent = q.front();
      q.pop();

      ans.push_back(parent);

      for (auto child : g[parent]) {
        q.push(child);
      }
    }

    return ans;
  }
};
// 77 ms
// 71.52 MB