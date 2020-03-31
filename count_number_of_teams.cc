class Solution {
 public:
  int numTeams(vector<int>& rating) {
    int ans = 0;

    int n = rating.size();

    for (int i = 0; i < n - 2; ++i) {
      for (int j = i + 1; j < n - 1; ++j) {
        for (int k = j + 1; k < n; ++k) {
          if (rating[i] < rating[j] && rating[j] < rating[k]) {
            ++ans;
          }
          if (rating[i] > rating[j] && rating[j] > rating[k]) {
            ++ans;
          }
        }
      }
    }

    return ans;
  }
};
// Runtime: 116 ms, faster than 52.03%
// Memory Usage: 7.5 MB, less than 100.00%

class Solution {
 public:
  int numTeams(vector<int>& rating) {
    int n = rating.size();

    int ans = 0;

    for (int i = 1; i < n - 1; ++i) {
      int less[2] = {};
      int greater[2] = {};

      for (int j = 0; j < n; ++j) {
        if (rating[i] < rating[j]) {
          ++greater[i < j];
        }

        if (rating[i] > rating[j]) {
          ++less[i < j];
        }
      }

      ans += greater[0] * less[1] + greater[1] * less[0];
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 99.63%
// Memory Usage: 7.7 MB, less than 100.00%