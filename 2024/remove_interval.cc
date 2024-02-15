class Solution {
 public:
  vector<vector<int>> removeInterval(vector<vector<int>>& intervals,
                                     vector<int>& toBeRemoved) {
    vector<vector<int>> ans;

    for (auto& i : intervals) {
      int start = i[0];
      int end = i[1];
      if (end < toBeRemoved[0]) {
        ans.push_back(i);
      } else if (start < toBeRemoved[0] && end > toBeRemoved[1]) {
        ans.push_back({start, toBeRemoved[0]});
        ans.push_back({toBeRemoved[1], end});
      } else if (start < toBeRemoved[0]) {
        ans.push_back({start, toBeRemoved[0]});
      } else if (end > toBeRemoved[1]) {
        ans.push_back({max(start, toBeRemoved[1]), end});
      }
    }

    return ans;
  }
};
// 56 ms
// 41.83 MB