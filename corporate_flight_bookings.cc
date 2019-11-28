class Solution {
 public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> ans(n);

    for (auto& booking : bookings) {
      ans[booking[0] - 1] += booking[2];

      if (booking[1] < n) {
        ans[booking[1]] -= booking[2];
      }
    }

    for (int i = 1; i < n; ++i) {
      ans[i] += ans[i - 1];
    }

    return ans;
  }
};
// Runtime: 268 ms, faster than 77.10%
// Memory Usage: 41.1 MB, less than 100.00%

class Solution {
 public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> ans(n);

    for (auto& booking : bookings) {
      for (int i = booking[0]; i <= booking[1]; ++i) {
        ans[i - 1] += booking[2];
      }
    }

    return ans;
  }
};
// Time Limit Exceeded