class Solution {
 public:
  vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
    sort(score.begin(), score.end(),
         [&](auto& a, auto& b) { return a[k] > b[k]; });

    return score;
  }
};
// Runtime 69 ms
// Memory 27.3 MB
// 2023.2.10 at 聊城市东昌路怡莱酒店