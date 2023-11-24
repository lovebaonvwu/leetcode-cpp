class Solution {
 public:
  vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    unordered_map<int, unordered_set<int>> mp;

    for (auto& log : logs) {
      mp[log[0]].insert(log[1]);
    }

    unordered_map<int, int> cnt;

    for (auto& [t, u] : mp) {
      ++cnt[u.size()];
    }

    vector<int> ans(k);

    for (int i = 0; i < k; ++i) {
      if (cnt.find(i + 1) != cnt.end()) {
        ans[i] = cnt[i + 1];
      }
    }

    return ans;
  }
};
// Runtime: 240 ms, faster than 73.38%
// Memory Usage: 85.4 MB, less than 63.77%

class Solution {
 public:
  vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    unordered_map<int, unordered_set<int>> mp;

    for (auto& log : logs) {
      mp[log[0]].insert(log[1]);
    }

    vector<int> ans(k);

    for (auto& [user, active] : mp) {
      ++ans[active.size() - 1];
    }

    return ans;
  }
};
// Runtime: 216 ms, faster than 94.41%
// Memory Usage: 85.5 MB, less than 63.77%