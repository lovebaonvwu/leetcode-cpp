class Solution {
 public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    set<int> win;
    map<int, int> lose;

    for (auto& m : matches) {
      win.insert(m[0]);
      ++lose[m[1]];
    }

    vector<vector<int>> ans(2);

    for (auto& w : win) {
      if (lose.find(w) == lose.end()) {
        ans[0].push_back(w);
      }
    }

    for (auto& l : lose) {
      if (l.second == 1) {
        ans[1].push_back(l.first);
      }
    }

    return ans;
  }
};
// Runtime: 826 ms, faster than 77.41%
// Memory Usage: 169.6 MB, less than 73.17%
// 2022.4.8 at 奥盛大厦