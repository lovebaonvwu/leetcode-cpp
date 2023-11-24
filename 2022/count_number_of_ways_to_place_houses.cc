class Solution {
 public:
  int countHousePlacements(int n) {
    long long house = 1, space = 1, total = 2;
    int mod = 1e9 + 7;

    for (int i = 2; i <= n; ++i) {
      house = space;
      space = total;

      total = (house + space) % mod;
    }

    return (total * total) % mod;
  }
};
// Runtime: 9 ms, faster than 62.36%
// Memory Usage: 6 MB, less than 55.46%
// 2022.6.30 at 奥盛大厦