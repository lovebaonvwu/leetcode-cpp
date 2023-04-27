class Solution {
 public:
  int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
    return (arrivalTime + delayedTime) % 24;
  }
};
// Runtime 5 ms
// Memory 5.9 MB