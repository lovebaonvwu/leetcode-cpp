class Solution {
 public:
  long long minimumTime(vector<int>& time, int totalTrips) {
    long long lo = 1, hi = *max_element(time.begin(), time.end()) *
                           static_cast<long long>(totalTrips);

    while (lo < hi) {
      long long mi = lo + (hi - lo) / 2;

      long long sum = 0;
      for (auto t : time) {
        sum += mi / t;
      }

      if (sum < totalTrips) {
        lo = mi + 1;
      } else {
        hi = mi;
      }
    }

    return lo;
  }
};
// Runtime: 383 ms, faster than 68.17%
// Memory Usage: 94.4 MB, less than 5.59%
// 2022.3.1 at 奥盛大厦 719