/**
 * Definition for a street.
 * class Street {
 * public:
 *     Street(vector<int> doors);
 *     void closeDoor();
 *     bool isDoorOpen();
 *     void moveRight();
 * };
 */
class Solution {
 public:
  int houseCount(Street* street, int k) {
    int i = 0;
    int sentinel = -1;

    int ans = 0;

    while (i < 2 * k) {
      if (street->isDoorOpen()) {
        if (sentinel == -1) {
          sentinel = i;
        } else {
          ans = max(ans, i - sentinel);
          street->closeDoor();
        }
      }

      street->moveRight();
      ++i;
    }

    return ans;
  }
};
// 96 ms
// 125.79 MB
// 兰州