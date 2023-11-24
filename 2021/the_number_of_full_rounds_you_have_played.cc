class Solution {
 public:
  int numberOfRounds(string startTime, string finishTime) {
    int startHour, startMin, stopHour, stopMin;

    startHour = stoi(startTime.substr(0, 2));
    startMin = stoi(startTime.substr(3, 2));
    stopHour = stoi(finishTime.substr(0, 2));
    stopMin = stoi(finishTime.substr(3, 2));

    int start = startHour * 60 + startMin;
    int stop = stopHour * 60 + stopMin;

    if (start > stop) {
      stop += 24 * 60;
    }

    start = (start / 15) + (start % 15 > 0);
    stop /= 15;

    return max(stop - start, 0);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 59.90%
// 2021.7.23 at 奥盛大厦