class Solution {
 public:
  string oddString(vector<string>& words) {
    int m = words.size();
    int n = words[0].size();

    int index = 0;
    for (int j = 0; j < n - 1; ++j) {
      unordered_map<int, pair<int, int>> mp;
      for (int i = 0; i < m; ++i) {
        int diff = words[i][j + 1] - words[i][j];
        if (mp.find(diff) == mp.end()) {
          mp[diff] = {1, i};
        } else {
          mp[diff] = {mp[diff].first + 1, i};
        }
      }

      if (mp.size() > 1) {
        index = mp.begin()->second.first == 1 ? mp.begin()->second.second
                                              : next(mp.begin())->second.second;
        break;
      }
    }

    return words[index];
  }
};
// Runtime 5 ms
// Memory 7.2 MB
// 2022.11.12 at 茗筑美嘉