class Solution {
 public:
  int maxBottlesDrunk(int numBottles, int numExchange) {
    int ans = 0;
    int empty = 0;
    int full = numBottles;
    while (full > 0) {
      ans += full;
      empty += full;
      full = 0;
      while (empty >= numExchange) {
        empty -= min(empty, numExchange);
        ++numExchange;
        ++full;
      }
    }

    return ans;
  }
};
// 0 ms
// 7.56 MB