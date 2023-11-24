class Solution {
 public:
  long long waysToBuyPensPencils(int total, int cost1, int cost2) {
    long long ans = 0;

    for (int i = 0; i * cost1 <= total; ++i) {
      ans += (total - i * cost1) / cost2 + 1;
    }

    return ans;
  }
};
// Runtime: 21 ms, faster than 100.00%
// Memory Usage: 5.8 MB, less than 100.00%
// 2022.4.18 at 奥盛大厦