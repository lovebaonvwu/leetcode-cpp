class Solution {
 public:
  int distanceTraveled(int mainTank, int additionalTank) {
    int ans = 0;
    while (mainTank > 0) {
      if (mainTank >= 5) {
        ans += 10 * 5;
        mainTank -= 5;
        mainTank += additionalTank-- > 0;
      } else {
        ans += 10 * mainTank;
        mainTank -= mainTank;
      }
    }

    return ans;
  }
};
// Runtime 20 ms
// Memory 5.9 MB