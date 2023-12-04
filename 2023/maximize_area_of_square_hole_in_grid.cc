class Solution {
 public:
  int maximizeSquareHoleArea(int n,
                             int m,
                             vector<int>& hBars,
                             vector<int>& vBars) {
    int h_gap = 1;
    sort(hBars.begin(), hBars.end());
    for (int i = 1, j = 0; i < hBars.size(); ++i) {
      if (hBars[i] == hBars[i - 1] + 1) {
        h_gap = max(h_gap, i - j + 1);
      } else {
        j = i;
      }
    }

    int v_gap = 1;
    sort(vBars.begin(), vBars.end());
    for (int i = 1, j = 0; i < vBars.size(); ++i) {
      if (vBars[i] == vBars[i - 1] + 1) {
        v_gap = max(v_gap, i - j + 1);
      } else {
        j = i;
      }
    }

    int min_gap = min(h_gap + 1, v_gap + 1);
    return min_gap * min_gap;
  }
};
// 9ms
// 27.98MB