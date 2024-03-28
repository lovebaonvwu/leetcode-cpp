class Solution {
 public:
  int numberOfPairs(vector<vector<int>>& points) {
    int ans = 0;
    int n = points.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j == i)
          continue;
        int ax = points[i][0];
        int ay = points[i][1];
        int bx = points[j][0];
        int by = points[j][1];

        if (bx < ax || by > ay)
          continue;

        bool sad = false;
        for (int k = 0; k < n; ++k) {
          if (k == i || k == j)
            continue;
          int px = points[k][0];
          int py = points[k][1];

          if (px >= ax && px <= bx && py <= ay && py >= by) {
            sad = true;
            break;
          }
        }

        ans += !sad;
      }
    }

    return ans;
  }
};
// 35 ms
// 32.15 MB