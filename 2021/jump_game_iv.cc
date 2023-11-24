class Solution {
 public:
  int minJumps(vector<int>& arr) {
    int n = arr.size();

    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < n; ++i) {
      mp[arr[i]].push_back(i);
    }

    vector<bool> visited(n);
    visited[0] = true;

    queue<int> q;
    q.push(0);

    int ans = 0;
    while (!q.empty()) {
      int cnt = q.size();

      while (cnt-- > 0) {
        auto i = q.front();
        q.pop();

        if (i == n - 1) {
          return ans;
        }

        vector<int>& next = mp[arr[i]];
        next.push_back(i - 1);
        next.push_back(i + 1);

        for (auto j : next) {
          if (j >= 0 && j < n && !visited[j]) {
            visited[j] = true;
            q.push(j);
          }
        }

        next.clear();
      }

      ++ans;
    }

    return ans;
  }
};
// Runtime: 340 ms, faster than 64.93%
// Memory Usage: 62.8 MB, less than 56.71%