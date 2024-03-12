class Solution {
 public:
  long long largestSquareArea(vector<vector<int>>& bottomLeft,
                              vector<vector<int>>& topRight) {
    long long ans = 0;
    int n = bottomLeft.size();

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (bottomLeft[i][0] >= topRight[j][0])
          continue;
        if (topRight[i][1] <= bottomLeft[j][1])
          continue;
        if (topRight[i][0] <= bottomLeft[j][0])
          continue;
        if (bottomLeft[i][1] >= topRight[j][1])
          continue;

        int x0 = max(bottomLeft[i][0], bottomLeft[j][0]);
        int y0 = max(bottomLeft[i][1], bottomLeft[j][1]);
        int x1 = min(topRight[i][0], topRight[j][0]);
        int y1 = min(topRight[i][1], topRight[j][1]);

        int side = min(abs(x1 - x0), abs(y1 - y0));
        ans = max(ans, 1LL * side * side);
      }
    }

    return ans;
  }
};
// 234 ms
// 58.82 MB