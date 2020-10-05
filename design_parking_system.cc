class ParkingSystem {
  int b;
  int m;
  int s;

 public:
  ParkingSystem(int big, int medium, int small) {
    b = big;
    m = medium;
    s = small;
  }

  bool addCar(int carType) {
    if (carType == 1) {
      if (b > 0) {
        --b;
        return true;
      }
    } else if (carType == 2) {
      if (m > 0) {
        --m;
        return true;
      }
    } else if (carType == 3) {
      if (s > 0) {
        --s;
        return true;
      }
    }

    return false;
  }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// Runtime: 88 ms, faster than 100.00%
// Memory Usage: 33.4 MB, less than 25.00%

class ParkingSystem {
  vector<int> p;

 public:
  ParkingSystem(int big, int medium, int small) { p = {big, medium, small}; }

  bool addCar(int carType) { return p[carType - 1]-- > 0; }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// Runtime: 92 ms, faster than 100.00%
// Memory Usage: 33.4 MB, less than 25.00%