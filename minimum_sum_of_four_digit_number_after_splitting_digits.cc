class Solution {
 public:
  int minimumSum(int num) {
    vector<int> d(4);

    for (int i = 0; i < 4; ++i) {
      d[i] = num % 10;
      num /= 10;
    }

    sort(d.begin(), d.end());

    return 10 * (d[0] + d[1]) + d[2] + d[3];
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.1 MB, less than 25.00%
// 2022.2.6 at 茗筑美嘉