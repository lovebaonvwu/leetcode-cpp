class Solution {
 public:
  vector<vector<int>> highFive(vector<vector<int>>& items) {
    map<int, vector<int>> mp;
    for (auto& i : items) {
      mp[i[0]].push_back(i[1]);
    }

    vector<vector<int>> ans;

    for (auto& [id, scores] : mp) {
      sort(scores.rbegin(), scores.rend());
      int sum = 0;
      for (int i = 0; i < 5; ++i) {
        sum += scores[i];
      }

      ans.push_back({id, sum / 5});
    }

    return ans;
  }
};
// Runtime 18 ms
// Memory 10.7 MB
// 2023.1.25 at 茗筑美嘉