class Solution {
 public:
  int countBalls(int lowLimit, int highLimit) {
    unordered_map<int, int> mp;

    int ans = 0;

    for (int i = lowLimit; i <= highLimit; ++i) {
      int num = 0, n = i;

      while (n > 0) {
        num += n % 10;
        n /= 10;
      }

      ++mp[num];

      ans = max(ans, mp[num]);
    }

    return ans;
  }
};
// Runtime: 36 ms, faster than 41.37%
// Memory Usage: 6.2 MB, less than 18.17%