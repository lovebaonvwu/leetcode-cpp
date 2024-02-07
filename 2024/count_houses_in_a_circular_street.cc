/**
 * Definition for a street.
 * class Street {
 * public:
 *     Street(vector<int> doors);
 *     void openDoor();
 *     void closeDoor();
 *     bool isDoorOpen();
 *     void moveRight();
 *     void moveLeft();
 * };
 */
class Solution {
 public:
  int houseCount(Street* street, int k) {
    while (k-- > 0) {
      if (street->isDoorOpen())
        street->closeDoor();
      street->moveRight();
    }

    int ans = 0;
    while (!street->isDoorOpen()) {
      street->openDoor();
      ++ans;
      street->moveRight();
    }

    return ans;
  }
};
// 16 ms
// 50.62 MB