class Solution {
  int ans = 0;

 public:
  int minSessions(vector<int>& tasks, int sessionTime) {
    int n = tasks.size();

    vector<int> sessions;

    ans = tasks.size();

    dfs(tasks, sessions, 0, sessionTime);

    return ans;
  }

  void dfs(vector<int>& t, vector<int>& sessions, int pos, int sessionTime) {
    if (sessions.size() >= ans) {
      return;
    }

    if (pos == t.size()) {
      ans = sessions.size();

      return;
    }

    for (int i = 0; i < sessions.size(); ++i) {
      if (sessions[i] + t[pos] <= sessionTime) {
        sessions[i] += t[pos];

        dfs(t, sessions, pos + 1, sessionTime);

        sessions[i] -= t[pos];
      }
    }

    sessions.push_back(t[pos]);

    dfs(t, sessions, pos + 1, sessionTime);

    sessions.pop_back();
  }
};
// Runtime: 48 ms, faster than 80.08%
// Memory Usage: 8.6 MB, less than 73.05%
// 2021.10.14 at 奥盛大厦