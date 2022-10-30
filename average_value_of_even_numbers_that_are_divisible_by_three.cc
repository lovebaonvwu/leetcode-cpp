class Solution {
 public:
  int averageValue(vector<int>& nums) {
    int sum = 0, cnt = 0;

    for (auto n : nums) {
      if (n % 2 == 0 && n % 3 == 0) {
        sum += n;
        ++cnt;
      }
    }

    return cnt == 0 ? 0 : sum / cnt;
  }
};
// Runtime: 32 ms, faster than 25.00%
// Memory Usage: 13.6 MB, less than 87.50%
// 2022.10.30 at 茗筑美嘉