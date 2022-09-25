class Solution {
 public:
  vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
    vector<pair<int, int>> h;
    for (int i = 0; i < heights.size(); ++i) {
      h.push_back({heights[i], i});
    }

    sort(h.rbegin(), h.rend());

    vector<string> ans;
    for (int i = 0; i < h.size(); ++i) {
      ans.push_back(names[h[i].second]);
    }

    return ans;
  }
};
// Runtime: 66 ms, faster than 58.33%
// Memory Usage: 20.7 MB, less than 91.67%
// 2022.9.25 at 茗筑美嘉