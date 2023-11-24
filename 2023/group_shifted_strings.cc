class Solution {
 public:
  vector<vector<string>> groupStrings(vector<string>& strings) {
    unordered_map<string, vector<string>> group;

    for (auto& s : strings) {
      string key;
      for (int i = 1; i < s.size(); ++i) {
        key += (s[i] - s[i - 1] + 26) % 26 + 'a';
      }

      group[key].push_back(s);
    }

    vector<vector<string>> ans;
    for (auto& [key, item] : group) {
      ans.push_back(item);
    }

    return ans;
  }
};
// Runtime 5 ms
// Memory 7.7 MB
// 2022.11.24 at 茗筑美嘉