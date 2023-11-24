class Solution {
 public:
  int minCostSetTime(int startAt,
                     int moveCost,
                     int pushCost,
                     int targetSeconds) {
    int mm = targetSeconds / 60;
    int ss = targetSeconds % 60;

    return min(cost(startAt, mm, ss, moveCost, pushCost),
               cost(startAt, mm - 1, ss + 60, moveCost, pushCost));
  }

  int cost(int pos, int mm, int ss, int move, int push) {
    if (min(mm, ss) < 0 || max(mm, ss) > 99) {
      return INT_MAX;
    }

    int res = 0;
    for (auto c : to_string(mm * 100 + ss)) {
      res += pos == (c - '0') ? 0 : move;
      res += push;
      pos = c - '0';
    }

    return res;
  }
};
// Runtime: 3 ms, faster than 47.95%
// Memory Usage: 5.9 MB, less than 64.39%
// 2022.2.10 at 奥盛大厦