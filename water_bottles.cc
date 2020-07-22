class Solution {
 public:
  int numWaterBottles(int numBottles, int numExchange) {
    int ans = 0;

    for (int empty = 0; numBottles > 0; numBottles /= numExchange) {
      ans += numBottles;

      numBottles += empty;

      empty = numBottles % numExchange;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 100.00%