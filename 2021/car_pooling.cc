class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int n = trips.size();

    vector<vector<int>> g(n, vector<int>(1001, 0));

    for (int i = 0; i < n; ++i) {
      auto& trip = trips[i];

      for (int j = trip[1]; j < trip[2]; ++j) {
        g[i][j] = trip[0];
      }
    }

    for (int col = 0; col < 1001; ++col) {
      int picks = 0;
      for (int row = 0; row < n; ++row) {
        picks += g[row][col];

        if (picks > capacity) {
          return false;
        }
      }
    }

    return true;
  }
};
// Runtime: 64 ms, faster than 11.49%
// Memory Usage: 43.3 MB, less than 5.09%

class Solution {
 public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int picks[1001] = {};

    for (auto& t : trips) {
      picks[t[1]] += t[0];
      picks[t[2]] -= t[0];
    }

    for (int i = 0; i < 1001; ++i) {
      if (i > 0) {
        picks[i] += picks[i - 1];
      }

      if (picks[i] > capacity) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 20 ms, faster than 87.80%
// Memory Usage: 9.5 MB, less than 94.75%