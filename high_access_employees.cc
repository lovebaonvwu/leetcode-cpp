class Solution {
 public:
  vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
    unordered_map<string, vector<int>> mp;
    for (auto& at : access_times) {
      auto& t = at[1];
      int a = (t[0] - '0') * 10 + (t[1] - '0');
      int b = (t[2] - '0') * 10 + (t[3] - '0');
      mp[at[0]].push_back(a * 60 + b);
    }

    for (auto& [name, t] : mp) {
      sort(t.begin(), t.end());
    }

    vector<string> ans;
    for (auto& [name, t] : mp) {
      for (int i = 2; i < t.size(); ++i) {
        if (t[i] - t[i - 2] < 60) {
          ans.push_back(name);
          break;
        }
      }
    }

    return ans;
  }
};
// 62ms
// 44.35MB