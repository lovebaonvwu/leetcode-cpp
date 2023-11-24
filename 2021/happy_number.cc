class Solution {
 public:
  bool isHappy(int n) {
    unordered_map<int, bool> record;

    while (n != 1) {
      if (record[n]) {
        return false;
      }

      record[n] = 1;

      int sum = 0;
      while (n > 0) {
        int r = n % 10;
        sum += r * r;

        n = n / 10;
      }

      n = sum;
    }

    return true;
  }
};  // 0ms ? 8ms