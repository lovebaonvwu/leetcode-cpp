class Solution {
 public:
  vector<int> survivedRobotsHealths(vector<int>& positions,
                                    vector<int>& healths,
                                    string directions) {
    int n = positions.size();
    vector<int> indexs(n);
    iota(indexs.begin(), indexs.end(), 0);
    sort(indexs.begin(), indexs.end(),
         [&](auto& a, auto& b) { return positions[a] < positions[b]; });

    vector<vector<int>> stk;
    for (int i = 0; i < n; ++i) {
      int idx = indexs[i];
      if (directions[idx] == 'R') {
        stk.push_back({healths[idx], idx, 1});
      } else {
        while (healths[idx] > 0 && !stk.empty() && stk.back()[2] == 1) {
          if (stk.back()[0] == healths[idx]) {
            healths[idx] -= stk.back()[0];
            stk.pop_back();
          } else if (stk.back()[0] > healths[idx]) {
            stk.back()[0] -= 1;
            healths[idx] = 0;
          } else {
            healths[idx] -= 1;
            stk.pop_back();
          }
        }

        if (healths[idx] > 0) {
          stk.push_back({healths[idx], idx, 0});
        }
      }
    }

    sort(stk.begin(), stk.end(), [](auto& a, auto& b) { return a[1] < b[1]; });

    vector<int> ans;
    for (int i = 0; i < stk.size(); ++i) {
      ans.push_back(stk[i][0]);
    }

    return ans;
  }
};
// 405 ms
// 220.8 MB