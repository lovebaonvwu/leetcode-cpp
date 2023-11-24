class Solution {
 public:
  int latestTimeCatchTheBus(vector<int>& buses,
                            vector<int>& passengers,
                            int capacity) {
    sort(buses.begin(), buses.end());
    sort(passengers.begin(), passengers.end());

    int ans = 0, prev = 0;

    for (int i = 0, j = 0; j < buses.size(); ++j) {
      int cnt = 0;

      while (i < passengers.size() && passengers[i] <= buses[j] &&
             cnt < capacity) {
        if (passengers[i] - prev > 1) {
          ans = passengers[i] - 1;
        }
        prev = passengers[i];
        ++i;
        ++cnt;
      }

      if (cnt < capacity && buses[j] - prev >= 1) {
        ans = buses[j];
      }
    }

    return ans;
  }
};
// Runtime: 191 ms, faster than 99.20%
// Memory Usage: 67 MB, less than 74.00%
// 2022.7.19 at 奥盛大厦