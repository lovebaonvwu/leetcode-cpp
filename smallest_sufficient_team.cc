class Solution {
 public:
  vector<int> smallestSufficientTeam(vector<string>& req_skills,
                                     vector<vector<string>>& people) {
    int m = req_skills.size();
    unordered_map<string, int> mp;
    for (int i = 0; i < m; ++i) {
      mp[req_skills[i]] = i;
    }

    int n = people.size();
    vector<int> skills(n);
    for (int i = 0; i < n; ++i) {
      for (auto& s : people[i]) {
        skills[i] |= (1 << mp[s]);
      }
    }

    vector<long long> dp(1 << m, -1);
    function<long long(int)> dfs = [&](int mask) -> long long {
      if (mask == 0) {
        return 0;
      }

      if (dp[mask] != -1) {
        return dp[mask];
      }

      for (int i = 0; i < n; ++i) {
        int newMask = mask & ~skills[i];
        if (newMask == mask) {
          continue;
        }

        long long res = dfs(newMask) | (1LL << i);
        if (dp[mask] == -1 ||
            __builtin_popcountll(res) < __builtin_popcountll(dp[mask])) {
          dp[mask] = res;
        }
      }

      return dp[mask];
    };

    long long res = dfs((1 << m) - 1);
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if ((res >> i) & 1) {
        ans.push_back(i);
      }
    }

    return ans;
  }
};
// 72ms
// 9.64mb