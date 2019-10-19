class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    for (int i = 0; i < flowerbed.size() && n > 0; ++i) {
      if (flowerbed[i] == 1) {
        continue;
      }

      if (i > 0 && flowerbed[i - 1] == 1) {
        continue;
      }

      if (i != flowerbed.size() - 1 && flowerbed[i + 1] == 1) {
        continue;
      }

      flowerbed[i] = 1;
      --n;
    }

    cout << n << endl;

    return n == 0;
  }
};
// Runtime: 12 ms, faster than 97.41%
// Memory Usage: 10.3 MB, less than 80.00%

class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (flowerbed.size() == 1) {
      if (flowerbed[0] == 1 && n > 0) {
        return false;
      } else {
        return true;
      }
    }

    if (n > 0 && flowerbed[0] == 0 && flowerbed[1] == 0) {
      flowerbed[0] = 1;
      --n;
    }

    for (int i = 1; i < flowerbed.size() - 1 && n > 0; ++i) {
      if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
        flowerbed[i] = 1;
        --n;
      }
    }

    if (n > 0 && flowerbed[flowerbed.size() - 1] == 0 &&
        flowerbed[flowerbed.size() - 2] == 0) {
      --n;
    }

    return n == 0;
  }
};
// Runtime: 16 ms, faster than 83.19%
// Memory Usage: 10.3 MB, less than 80.00%

class Solution {
 public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (flowerbed.size() == 1) {
      if (flowerbed[0] == 1 && n > 0) {
        return false;
      } else {
        return true;
      }
    }

    if (n > 0 && flowerbed[0] == 0 && flowerbed[1] == 0) {
      flowerbed[0] = 1;
      --n;
    }

    for (int i = 1; i < flowerbed.size() - 1 && n > 0; ++i) {
      if (flowerbed[i] == 1) {
        continue;
      } else if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 &&
                 flowerbed[i + 1] == 0) {
        flowerbed[i] = 1;
        --n;
      } else if (flowerbed[i] == 0 &&
                 (flowerbed[i - 1] == 0 || flowerbed[i + 1] == 0)) {
        continue;
      }
    }

    if (n > 0 && flowerbed[flowerbed.size() - 1] == 0 &&
        flowerbed[flowerbed.size() - 2] == 0) {
      --n;
    }

    return n == 0;
  }
};
// Runtime: 16 ms, faster than 83.19%
// Memory Usage: 10.3 MB, less than 80.00%