class Solution {
 public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    vector<int> p1 = coordinates[0];
    vector<int> p2 = coordinates[1];

    for (int i = 2; i < coordinates.size(); ++i) {
      vector<int> p = coordinates[i];

      if ((p[1] - p1[1]) * (p[0] - p2[0]) != (p[0] - p1[0]) * (p[1] - p2[1])) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 12 ms, faster than 57.36%
// Memory Usage: 10.3 MB, less than 100.00%