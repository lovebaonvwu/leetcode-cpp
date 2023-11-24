class Solution {
 public:
  int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    int ans = 0;

    for (int i = 0; i < startTime.size(); ++i) {
      if (queryTime >= startTime[i] && queryTime <= endTime[i]) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 100.00%
// Memory Usage: 11.1 MB, less than 100.00%