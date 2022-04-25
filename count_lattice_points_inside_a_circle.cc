class Solution {
 public:
  int countLatticePoints(vector<vector<int>>& circles) {
    set<pair<int, int>> st;

    for (auto& c : circles) {
      const int& x = c[0];
      const int& y = c[1];
      const int& r = c[2];

      for (int i = x - r; i <= x + r; ++i) {
        for (int j = y - r; j <= y + r; ++j) {
          if ((i - x) * (i - x) + (j - y) * (j - y) <= r * r) {
            st.insert({i, j});
          }
        }
      }
    }

    return st.size();
  }
};
// Runtime: 1221 ms, faster than 45.45%
// Memory Usage: 25 MB, less than 18.18%
// 2022.4.25 at 奥盛大厦